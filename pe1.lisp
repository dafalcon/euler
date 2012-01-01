(loop for i from 1 to 999 
	  if (or (zerop (mod i 3))
			 (zerop (mod i 5))) sum i)

