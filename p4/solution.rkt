#lang racket


;; A church-compiler
(provide church-encode)

;; for an input language:
;
; e ::= (letrec ([x (lambda (x ...) e)]) e)    
;     | (let ([x e] ...) e)  
;     | (lambda (x ...) e)
;     | (e e ...)    
;     | x  
;     | (and e e) | (or e e)
;     | (if e e e)
;     | (prim e) | (prim e e)
;     | datum
; datum ::= nat | (quote ()) | #t | #f 
; nat ::= 0 | 1 | 2 | ... 
; x is a symbol
; prim is a primitive operation in:
(define prims '(+ * - add1 sub1 cons car cdr null? not zero?))

;; To an output language:
;
; e ::= (lambda (x) e)
;     | (e e)
;     | x
;



(define (prim? prim)
  (if (member prim prims) #t #f))

(define (churchify-prim prim)
  (string->symbol (string-append "church:" (symbol->string prim))))

(define (churchify e)
  (match e
         ; Tagged expressions
         [`(letrec ([,f (lambda (,args ...) ,e0)]) ,e1)
          (churchify `(let ([,f (Y-comb (lambda (,f) (lambda ,args ,e0)))]) ,e1))]

         [`(let ([,xs ,e0s] ...) ,e1)
          (churchify `((lambda ,xs ,e1) . ,e0s))]

         [`(lambda () ,e0)
          `(lambda (_) ,(churchify e0))]
         [`(lambda (,x) ,e0)
          `(lambda (,x) ,(churchify e0))]
         [`(lambda (,x . ,rest) ,e0)
          `(lambda (,x) ,(churchify `(lambda ,rest ,e0)))]

         [`(and ,e0 ,e1)
          (churchify `(if ,e0 (if ,e1 #t #f) #f))]

         [`(or ,e0 ,e1)
          (churchify `(if ,e0 #t (if ,e1 #t #f)))]

         [`(if ,e0 ,e1 ,e2)
          (churchify `(,e0 (lambda () ,e1) (lambda () ,e2)))]

         [`(,(? prim? prim) . ,args)
          (churchify `(,(churchify-prim prim) . ,args))]

         ; Variables
         [(? symbol? x) x]

         ; Datums
         [(? natural? nat)
          (define (wrap nat)
            (if (= 0 nat) 'x `(f ,(wrap (- nat 1)))))
          (churchify `(lambda (f) (lambda (x) ,(wrap nat))))]
         [''() (churchify '(lambda (when-cons when-null) (when-null)))]
         [#t (churchify '(lambda (tt ft) (tt)))]
         [#f (churchify '(lambda (tt ft) (ft)))]

         ; Untagged application
         [`(,fun)
          ;(churchify `(,fun (lambda (_) _)))]
          `(,(churchify fun) (lambda (x) x))]
         [`(,fun ,arg)
          `(,(churchify fun) ,(churchify arg))]
         [`(,fun ,arg . ,rest)
          (churchify `((,fun ,arg) . ,rest))]))


(define (church-encode e)
  (define Y-comb `((lambda (u) (u u)) (lambda (y) (lambda (mk) (mk (lambda (x) (((y y) mk) x)))))))

  (define church:null? `(lambda (p) (p (lambda (a b) #f) (lambda () #t))))
  
  (define church:cons `(lambda (a b) (lambda (when-cons when-null) (when-cons a b))))
  
  (define church:car `(lambda (p) (p (lambda (a b) a) (lambda () (lambda (x) x)))))
  
  (define church:cdr `(lambda (p) (p (lambda (a b) b) (lambda () (lambda (x) x)))))
  
  (define church:add1 `(lambda (n0) (lambda (f x) (f ((n0 f) x)))))
  
  (define church:sub1 `(lambda (n0) (lambda (f) (lambda (y) (((n0
                                                               (lambda (g) (lambda (h) (h (g f)))))
                                                              ; uses n0 to produce a chain of linked closures
                                                              ; with |n0|-1 linked functions g -> (lambda (h) (h (g f)))
                                                              ; The first g and last h are then (lambda (_) y) and id,
                                                              ; so in a sense it's computing |n0|+1-2
                                                              (lambda (_) y))
                                                             (lambda (x) x))))))

  (define church:zero? `(lambda (n0) ((n0 (lambda (b) #f)) #t)))

  (define church:+ `(lambda (n0 n1) (lambda (f x) ((n1 f) ((n0 f) x)))))
  
  (define church:- `(lambda (n0 n1) ((n1 ,church:sub1) n0)))

  (define church:* `(lambda (n0 n1) (lambda (f) (lambda (x) ((n0 (n1 f)) x)))))

  (define church:= `(lambda (n0 n1) (and (,church:zero? (,church:- n0 n1)) (,church:zero? (,church:- n1 n0)))))

  (define church:not `(lambda (bool) (if bool #f #t)))
  
  (churchify
   `(let ([Y-comb ,Y-comb]
          [church:null? ,church:null?]
          [church:cons ,church:cons]
          [church:car ,church:car]
          [church:cdr ,church:cdr]
          [church:add1 ,church:add1]
          [church:sub1 ,church:sub1]
          [church:+ ,church:+]
          [church:- ,church:-]
          [church:* ,church:*]
          [church:zero? ,church:zero?]
          [church:= ,church:=]
          [church:not ,church:not])
      ,e)))


