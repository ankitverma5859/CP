'''
https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1
'''

class Solution:
	def topK(self, nums, k):
		#Code here
		freq = {}
		for item in nums:
		    if item in freq:
		        freq[item] += 1
		    else:
		        freq[item] = 1
		
		ans = sorted(freq.items(), key = lambda x : (x[1], x[0]), reverse=True)[:k]
		
		return [key for key, freq in ans]
