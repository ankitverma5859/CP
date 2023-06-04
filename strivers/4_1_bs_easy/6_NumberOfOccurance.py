'''
https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence
'''

class Solution:

	def count(self,nums, n, x):
		start_idx = -1
		end_idx = -1
		
		#First Occurance
		l = 0
		r = len(nums) - 1
		while l <= r:
		    mid = (l+r)//2
		    if x == nums[mid]:
		        if mid-1 >= 0 and nums[mid] == nums[mid-1]:
		            r = mid - 1
		        else:
		            start_idx = mid
		            break
		    elif x < nums[mid]:
		        r = mid - 1
		    elif x > nums[mid]:
		        l = mid + 1
		        
		#Last Occurance
		l = 0
		r = len(nums) - 1
		while l <= r:
		    mid = (l+r)//2
		    if x == nums[mid]:
		        if mid+1 < len(nums) and nums[mid] == nums[mid+1]:
		            l = mid + 1
		        else:
		            end_idx = mid
		            break
		    elif x < nums[mid]:
		        r = mid - 1
		    elif x > nums[mid]:
		        l = mid + 1	
		  
	    count = 0      
	    if start_idx != -1 and end_idx != -1:
	        count = end_idx - start_idx + 1
	  
	    return count
