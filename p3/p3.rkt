#lang racket   	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
;   	
; Project 3 -- Exercises in Racket
;	
; The goal of this lab is to write six/seven functions in Racket.  	
;   	
; Each is described in comments below. The last is optional for CS 401.  	
;  	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  	


(provide list-reverse 
         list-append 
         zip-lists  
         slice-list 
         palindrome?  	
         )   	
  	

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

   	
; Define a list-reverse function that takes a list to its reverse  	
;;; e.g., (list-reverse '(1 2 3)) => '(3 2 1)
(define (list-reverse lst)  	
  (if (<= (length lst) 1)
      lst
      (append 
        (list-reverse (rest lst)) 
        (cons (first lst) '())
        )
  ) 
) 

(define (length l)
  (if (empty? l)
    0
    (+ 1 (length (rest l)))
  )
)  	


; Define an list-append function which takes two lists and returns their concatenation   	
;;; e.g., (list-append '(1) '(2 3)) => '(1 2 3)  	
(define (list-append lst0 lst1) 
  (if (empty? lst0)
    lst1
    (cons (first lst0) (list-append (rest lst0) lst1)))
)  	


; Define a zip-lists function that takes multiple lists and zips them together into   	
; a list of lists where each inner list is a list of all ith elements from input lists  	
;;; e.g., (zip-lists '(1 2 3) '(a b c)) => '((1 a) (2 b) (3 c))   	
; zipping should stop at the end of the shortest list and should support zipping 
; any number of lists together
;;; e.g., (zip-lists '(1) '(2 3 4) '(5 6)) => '((1 2 5)) 
(define (zip-lists . args) 
  (cond [(empty? args) '()]
        [(my-empty args) '()]
        [else (helper args 0)]
  ))

(define (helper args n)
  (cond [(= n (smallestlength args)) '()]
        [(cons (map (lambda (x) (at x n)) args) (helper args (+ 1 n)))]
  )
)

(define (my-empty args)
  (if (<= (length args) 1)
    (or (empty? args) (empty? (first args)))
    (or (empty? (first args)) (my-empty (rest args)))
  )
)

(define (smallestlength args)
  (cond [(empty? args) 0]
        [(= 1 (length args)) (length (first args))]
        [(min (length (first args)) (smallestlength (rest args)))]
  )
)

; Define a slice-list function that takes a list, start position, and  	
; end position to a list of elements between the given positions (inclusive)
;;; e.g., (slice-list '(1 2 3 4 5) 2 3) => '(3 4)  	
; any part of the requested list that is non-existent should be trimmed   	
;;; e.g., (slice-list '(1 2) 1 4) => '(2)  	
; if the range of the slice is empty/nonexistent, then the result should be '()
(define (slice-list lst n m)
  (if (or (< n 0) (or (empty? lst) (> n m)))
      '()
      (if (and (= n m) (< m (length lst)))
        (cons (at lst n) '())
        (if (>= m (length lst))
            (slice-list lst n (- (length lst) 1))
            (list-append (cons (at lst n) '()) (slice-list lst (+ n 1) m))
            )
      )
  )
)

(define (at lst index)
  (if (= 0 index)
    (car lst)
    (at (cdr lst) (- index 1))
  )
)

; Define a palindrome? predicate that only returns true for strings that are palindromes
;;; e.g., (palindrome? "abcdcba") => #t  	
(define (palindrome? s)  	
  (equal? (string-reverse s) s)
  )  	

(define (string-reverse s)
  (if (<= (string-length s) 1)
    s
    (string-append (string-reverse (substring s 1)) (substring s 0 1))
    )
)