#lang racket

(require "lab3.rkt")

(if (not (equal? (dist (cons 0 1) (cons 3 4))
                 (let ([d1 (- 3 0)]
                       [d2 (- 4 1)])
                   (sqrt (+ (* d1 d1) (* d2 d2))))))
    (exit 1) (void))
(if (not (equal? (dist (cons 5 8) (cons 9 -2))
                 (let ([d1 (- 9 5)]
                       [d2 (- -2 8)])
                   (sqrt (+ (* d1 d1) (* d2 d2))))))
    (exit 1) (void))
(if (not (equal? (dist (cons 10 10) (cons 0 0))
                 (let ([d1 (- 10 0)]
                       [d2 (- 10 0)])
                   (sqrt (+ (* d1 d1) (* d2 d2))))))
    (exit 1) (void))
