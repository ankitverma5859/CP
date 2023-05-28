'''
https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest
'''

# Naive : Sort and return second largest
# This works only when there are no duplicates.
# O(nlogn)
class Solution:

	def print2largest(self,arr, n):
		return sorted(arr)[-2]

# Approach: 
# In first pass find the largest element
# In second pass find the second largest element
import heapq

class Solution:

	def print2largest(self,arr, n):
        largest = max(arr)
        
	# FIRST PASS
        second_largest = float("-inf")
        
	# SECOND PASS
        for item in arr:
            if item > second_largest and item != largest:
                second_largest = item
                
        return -1 if second_largest == float("-inf") else second_largest
	
# Using max-heap
import heapq

class Solution:

	def print2largest(self,arr, n):
	    distinct = list(set(arr))
		heapq._heapify_max(distinct)
		
		if len(distinct) > 1:
		    heapq._heappop_max(distinct)
		    return heapq._heappop_max(distinct)
		else:
		    return -1
  
  
# Using heapq nlargest
import heapq

class Solution:

	def print2largest(self,arr, n):
	    distinct = set(arr)
	    if len(distinct) > 1:
		    return heapq.nlargest(2, set(arr))[1]
		return -1
