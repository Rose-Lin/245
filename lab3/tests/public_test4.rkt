#lang racket

(require "lab3.rkt")

(if (not (= (mean '(1 2 3)) 2)) (exit 1) (void))
(if (not (= (mean '(-2 0 2)) 0)) (exit 1) (void))
(if (not (= (mean '(0 0 0)) 0)) (exit 1) (void))
(if (not (= (mean '(5 10 20)) (/ (+ 5 10 20) 3))) (exit 1) (void))
