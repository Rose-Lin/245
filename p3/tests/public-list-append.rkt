#lang racket

(require "../p3.rkt")



(if (equal? (list-append '(2 3 4) '()) '(2 3 4))
    (exit 0)
    (exit 1))

(if (equal? (list-append '(2 3 4) '(5 6)) '(2 3 4 5 6))
    (exit 0)
    (exit 1))


(if (equal? (list-append '(4) '(1 )) '(4 1))
    (exit 0)
    (exit 1))


(if (equal? (list-append '() '()) '())
    (exit 0)
    (exit 1))