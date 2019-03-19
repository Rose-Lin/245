#lang racket

(require "lab3.rkt")

(if (not (equal? (max-two 3 4) 4)) (exit 1) (void))
(if (not (equal? (max-two 4 3) 4)) (exit 1) (void))
(if (not (equal? (max-two -2 1) 1)) (exit 1) (void))
(if (not (equal? (max-two 0 0) 0)) (exit 1) (void))

(exit 0)
