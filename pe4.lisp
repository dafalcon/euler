(defun palindromep (s)
;  (print s)
  (equalp s (reverse s)))

(defun foo (upper-bound lower-bound)
  (setf maxpal 0)
  (loop for i downfrom upper-bound to lower-bound do
		(loop for j downfrom i to lower-bound do
			  (let ((test (* i j)))
				(if (and (palindromep (write-to-string test))
						 (> test maxpal))
					(progn
					  (format t "~D ~D ~D~%" i j test)
					  (setf maxpal test))
				  ))))
  maxpal)

;; 
(defun largest-product-palindrome (upper-bound lower-bound)
  (loop for i downfrom upper-bound to lower-bound 
		maximize (loop for j downfrom upper-bound to i
					   and test = (* i j)
					   maximize (progn 
								  (format t "~D ~D ~D~%" i j test)
								  (if (palindromep (write-to-string test)) test 0)))))

;; start from the max integer and work your way down looking for
;; palindromes that divide into 2 3 digit integers
(defun palindromes (upper-bound lower-bound)
  (loop for i downfrom (* upper-bound upper-bound) to (* lower-bound lower-bound) do
		(setf answer (if (palindromep (write-to-string i))
					   (loop for j downfrom upper-bound to lower-bound do
							 (let ((test (/ i j)))
							   (if (and (integerp test)
									  (>= test lower-bound)
									  (<= test upper-bound))
								 (progn
								   ;(format t "~D ~D ~D~%" i j test)
								   (return i)))))))
		(if answer (return answer))))
							 

;(print (largest-product-palindrome 999 100))
;(print (largest-product-palindrome 100 1))
;(print (foo 9999 1000))
;(print (foo 999 100))
;(print (palindromes 999 100))
;(print (palindromes 9999 1000))
(print (palindromes 99999 10000))
