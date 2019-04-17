#lang racket

;;;;foldl stuff
(foldl (λ (a b result)
         (* result (- a b)))
       1
       '(1 2 3)
       '(4 5 6))

(foldr (λ (a b result)
         (* result (- a b)))
       1
       '(1 2 3)
       '(4 5 6))

(foldl (λ (v l) (cons (add1 v) l)) '() '(1 2 3 4))

((λ (a b result)
   (begin
     ;(display a)
     (* result (- a b))))
   1 3 4)

(define (concat-s l)
  (foldl (λ (next-ele acc)
         (string-append next-ele acc))
  ''
  (reverse l)))

;((λ (a) ((λ (b) (- a b)) 2) 3))
((lambda (a b) (+ a b)) 2 3)
(define l '(2 5 3 4))
#;(foldl (λ (lst cur-max)
         (begin
         (max cur-max (first lst))))
       (first l)
       l)

(define (highest-number xs)
;  (define (max x1 x2)
;    (if (> x1 x2) x1 x2))
  (foldl max (first xs) (rest xs)))

(highest-number '(1 2 3 4))


;;;U Combinator/recursion
(define Y ((λ (x) (x x)) (λ (y) (λ (f)
                                  (f (λ (x) (((y y) f) x)))))))

(define U (λ (f) (f f)))

(define (fib x)
  (if (or (= 1 x) (= 0 x))
      1
      (+ (fib (- x 1)) (fib (- x 2)))))
(fib 10)
  
(let ([fib1 (λ (fib2)
             (λ (x)
               (if (or (= x 1) (= x 0))
                   1
                   (+ ((fib2 fib2) (- x 1)) ((fib2 fib2) (- x 2))))))])
  ;((U fib1) 10 gives the same answer
  ((fib1 fib1) 10))

;((Y fib1) 10)

(letrec ([fib (λ (x)
                (if (or (= x 1) (= x 0))
                    1
                    (+ (fib (- x 1)) (fib (- x 2)))))])
  (fib 10))


(let ([fib (U (λ (f)
                   (λ (x)
                     (if (or (= x 1) (= x 0))
                         1
                         (+ ((f f) (- x 1)) ((f f) (- x 2)))))))])
  (fib 10))

(let ([myfib (Y (lambda (f)
                 (lambda (x)
                   (if (< x 2)
                       1
                       (+ (f (- x 1)) (f (- x 2)))))))])
  (myfib 5))

           