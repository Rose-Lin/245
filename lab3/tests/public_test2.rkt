#lang racket

(require "lab3.rkt")

(if (not (equal? (max-of-list '(1)) 1)) (exit 1) (void))
(if (not (equal? (max-of-list '(1 2 3)) 3)) (exit 1) (void))
(if (not (equal? (max-of-list '(-2 2 3)) 3)) (exit 1) (void))
(if (not (equal? (max-of-list '(-1 -1 5 2 5 8 -3 -2)) 8)) (exit 1) (void))
