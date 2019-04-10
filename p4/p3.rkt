#lang racket   	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;   	
;  	
; Project 4 -- Simple Interpreters 
;   	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;   	

(provide interp-arith  	
         reduce-lambda)  	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
;  	
; Honor pledge (please write your name.)   	
;   	
; I **Rose Lin** have completed this code myself, without 
; unauthorized assistance, and have followed the academic honor code.
;  	
; Edit the code below to complete your solution.   	
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Define function interp-arith---an arithmetic interpreter for the language:  	
; e ::= (+ e e) | (- e e) | (* e e) | (** e e) | n
; encoded as lists, where n is a number? and ** performs exponentiation  	
;;; e.g., (interp-arith '(+ (* 2 3) (- 11 (** 2 3)))) => 9  	
(define (interp-arith e)   
	(match e
		[(? number? n) n]
		[`(+ ,e1 ,e2) (+ (interp-arith e1) (interp-arith e2))]
		[`(- ,e1 ,e2) (- (interp-arith e1) (interp-arith e2))]
		[`(* ,e1 ,e2) (* (interp-arith e1) (interp-arith e2))]
		[`(** ,e1 ,e2) (expt (interp-arith e1) (interp-arith e2))]
	)
)
   	
   	
; Define a function reduce-lambda, that takes a lambda term in language:
; e ::= (lambda (x) e) | (e e) | x   (encoded as a list; x is a symbol?) 
; and performs a single step of beta-reduction using CBN evaluation   	
;;; e.g., (interp-lambda '((lambda (a) a) ((lambda (b) b) (lambda (c) c))))  	
;;;          => '((lambda (b) b) (lambda (c) c)) 
(define (reduce-lambda exp) 
	(if (value? exp)
		exp
		(↝ exp)
	)
)  	

(define (value? e)
	(match e
		[`(lambda (,e1) ,body) #t]
		[else #f]
	)
)

(define (↝ state)
  (match state
    [`((λ (,x) ,body) ,(? value? v)) (capture-avoiding-subset body x v)]
    [`(,(? value? v) ,e1) e1]
    [`(,e0 ,e1) `(,(↝ e0) ,e1)]))

(define (capture-avoiding-subset e x e1)
	(match e
		[`(lambda (,y) ,body)
			(if (equal? x y)
				(let ([z (fresh-var (free-vars body))])
					`(lambda (,z) ,(capture-avoiding-subset (capture-avoiding-subset body y z)
					x
					e1)))
				`(lambda (,y) ,(capture-avoiding-subset body x e1)))]
		[(? symbol? y) (if (equal? x y) e1 y)]
		[`(,e2 ,e3) `(,(capture-avoiding-subset e2 x e1) ,(capture-avoiding-subset e3 x e1))]
	)
)

(define (free-vars e)
	(match e
		[`(lambda (,x) ,body) (set-subtract (free-vars body) (set x))]
		[(? symbol? x) (set x)]
		[`(,e0 ,e1) (set-union (free-vars e0) (free-vars e1))]
	)
)

(define (fresh-var s)
	(let ([x (gensym)])
		(if (not (set-member? s x)) x (fresh-var s))
	)
)
