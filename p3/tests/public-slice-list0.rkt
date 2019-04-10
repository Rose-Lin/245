#lang racket

(require "../p3.rkt")

(if (equal? (slice-list '(0 1 2 3 4 5 6 7 8 9) 0 3) '(0 1 2 3))
    (exit 0)
    (exit 1))

(if (equal? (slice-list '(0 1 2 3 4 5 6 7 8 9) 0 0) '(0))
    (exit 0)
    (exit 1))

(if (equal? (slice-list '() 0 3) '())
    (exit 0)
    (exit 1))

(if (equal? (slice-list '(0 1 2 3 4 5 6 7 8 9) 4 5) '(4 5))
    (exit 0)
    (exit 1))

(if (equal? (slice-list '(0 1 2 3 4 5 6 7 8 9) 4 10) '(4 5 6 7 8 9))
    (exit 0)
    (exit 1))

(if (equal? (slice-list '(0 1 2 3 4 5 6 7 8 9) -4 10) '())
    (exit 0)
    (exit 1))