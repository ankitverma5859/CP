'''
https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s
'''

class Solution:

	def rowWithMax1s(self,arr, n, m):
		rows = n
		cols = m
		row_with_max_1s = -1
		curr_max_1s = -1
		
		
		for row_idx in range(rows):
		    l = 0
		    r = cols - 1
		    
		    # Find the first 1's index in the row
		    while arr[row_idx][l] != 1:
		        l += 1
		        if l >= cols: 
		            break
		  
		    # Find the last 1's index in the row
		    while arr[row_idx][r] != 1:
		        r -= 1
		        if r < 0:
		            break
		    
		    if r-l+1 > curr_max_1s:
		        curr_max_1s = r-l+1
		        row_with_max_1s = row_idx
		    
	    return row_with_max_1s
