#lang racket

(require "../p3.rkt")



(if (equal? (list-reverse '(3 4 2)) '(2 4 3))
    (exit 0)
    (exit 1))


