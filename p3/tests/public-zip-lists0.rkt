#lang racket

(require "../p3.rkt")


(if (equal? (zip-lists) '())
    (exit 0)
    (exit 1))

(if (equal? (zip-lists '(1 2)) '(1 2))
    (exit 0)
    (exit 1))

(if (equal? (zip-lists '(1 2) '(2 3)) '((1 2) (2 3)))
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '(1) '(2 3)) '((1 2) ))
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '(1 2) '() '(3 4) '(7 7)) '())
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '() '(1 2)) '())
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '(3 4 5) '(1 2)) '((3 1) (4 2)))
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '(1) '(2 3 4) '(5 6)) '((1 2 5)))
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '(1 4) '(2 3) '(5 6 8)) '((1 2 5) (4 5 6)))
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '() '(2 3) '(5 6 8)) '())
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '(1 2 3) '(a b c)) '((1 a) (2 b) (3 c)))
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '(1 2 3 4) '(a b c d)) '((1 a) (2 b) (3 c) (4 d)))
	(exit 0)
    (exit 1)
)

(if (equal? (zip-lists '(1 2 3) '(a)) '((1 a)))
	(exit 0)
    (exit 1)
)
