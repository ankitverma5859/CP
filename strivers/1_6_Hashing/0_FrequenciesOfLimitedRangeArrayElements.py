'''
https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0
'''

class Solution:
    #Function to count the frequency of all elements from 1 to N in the array.
    def frequencyCount(self, arr, N, P):
        counts = {}
        
        for item in arr:
            if item in counts:
                counts[item] += 1
            else:
                counts[item] = 1
        
        for idx, val in enumerate(arr):
            if idx < P and idx+1 in counts:
                arr[idx] = counts[idx+1]
            else:
                arr[idx] = 0

        return
