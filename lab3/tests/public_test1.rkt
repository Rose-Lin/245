#lang racket

(require "lab3.rkt")

(if (not (equal? (max-three 3 4 5) 5)) (exit 1) (void))
(if (not (equal? (max-three -2 4 3) 4)) (exit 1) (void))
(if (not (equal? (max-three -15 1 5) 5)) (exit 1) (void))
(if (not (equal? (max-three 0 0 0) 0)) (exit 1) (void))
