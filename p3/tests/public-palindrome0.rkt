#lang racket

(require "../p3.rkt")

(if (palindrome? "aba")
    (exit 0)
    (exit 1))


(if (palindrome? "arbra")
    (exit 0)
    (exit 1))

