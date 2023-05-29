'''
https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicate-elements-from-sorted-array
'''

class Solution:	
	def remove_duplicate(self, A, N):
    # Two pointer approach
		i, j = 0, 1
		A_size = len(A)
		
		while j < A_size:
		    if A[i] != A[j]:                                # if same element is found, swap it with i+1 or the next index
		        A[i+1], A[j] = A[j], A[i+1] 
		        i += 1
		    j += 1                                          # move until you find a distinct/unique element
		return i+1
  
  
