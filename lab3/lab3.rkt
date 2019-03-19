;;   	
;; Lab 3 -- Introductory Racket programming
;;   	
;; This lab will have you write a few basic Racket functions using  	
;; various primitives that operate on lists, pairs, etc.. It will also  	
;; test your skills with recursion.  	
#lang racket  	

(provide (all-defined-out))  	

;; 
;; Honor pledge (please write your name.)
;;
;; I **Rose Lin** have completed this code myself, without
;; unauthorized assistance, and have followed the academic honor code.  	
;;   	
;; Edit the code below to complete your solution.  	
;;  	

; Calculate the maximum of 3 numbers 
(define (max-three x y z)
	(if (equal? (max-two x y) x )
		(max-two x z)
		(max-two y z))
)   	

; Calculate the maximum of 2 numbers  	
(define (max-two x y) 
	(if (> x y)
  		x
  		y))   	

; Calculate the maximum of 3 numbers 
; Consider using:   	
;   - empty?   	
;   - first (gets first element of a non-empty list)
;   - rest  (gets the rest of a non-empty  list)  	
(define (max-of-list l)  	
	(if (equal? (length l) 1) 
		(first l)
		(max-two (first l) (max-of-list (rest l))))
)	

(define (length l)
	(if (empty? l)
		0
		(+ 1 (length (rest l)))
	)
)

; You can create "pairs" in Racket by using `cons`
;   (cons 1 2) <-- Creates a pair  of (1 . 2) 
;
; You can then access the first element of the pair by using `car`,	
; and the second element of the pair by using `cdr`.  	
;    (car (cons 1 2)) --> 1  	
;    (cdr (cons 1 2)) --> 2
;
; Your job here is to calculate the distance between two points, where   	
; each point is a pair (x . y)   	
; 
; You should also consider using sqrt   	
(define (dist p0 p1)   	
	(sqrt (+ (* (- (car p0) (car p1)) (- (car p0) (car p1))) 
			(* (- (cdr p0) (cdr p1)) (- (cdr p0) (cdr p1)))
			)
	)
)

; Calculate the average value of a list of numbers. Consider also 
; using the function `length`, which returns the length of a list.
; You might want to define a "helper function" to sum each element of  	
; the list. You can of course add extra ones
(define (mean l)  	
	(if (empty? l)
		0
		(/ (sum l) (length l))
	)
)   	

(define (sum l)
	(if (equal? (length l) 1)
		(first l)
		(+ (first l) (sum (rest l)))
	)
)