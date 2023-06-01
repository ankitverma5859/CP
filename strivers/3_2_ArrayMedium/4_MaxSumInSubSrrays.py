'''
https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category=&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays
'''

# Approach 1: 
# Generate Subarrays, find smallest and second smallest, find max-sum
# O(n^3)
class Solution:
    def pairWithMaxSum(self, nums, N):
        nums_size = len(nums)
        max_sum = float("-inf")
        
        #print("Subarrays:")
        subarrays = []
        for idx1 in range(nums_size):
            curr_subarray = [nums[idx1]]
            for idx2 in range(idx1+1, nums_size):
                curr_subarray.append(nums[idx2])
                subarrays.append(curr_subarray.copy())
        
                smallest = float("inf")
                second_smallest = float("inf")
                '''
                # Find Smallest First Traversal
                for num in curr_subarray:
                    if num < smallest:
                        smallest = num
                
                # Find Second Samllest in anothe traversal
                for num in curr_subarray:
                    if num < second_smallest and num > smallest:
                        second_smallest = num
                '''
                for num in curr_subarray:
                    if num < smallest:
                        second_smallest = smallest
                        smallest = num
                    elif num < second_smallest and num != smallest:
                        second_smallest = num
                
                #print(curr_subarray)
                #print(f"Smallest: {smallest} Second Smallest: {second_smallest}\n")
                if smallest + second_smallest > max_sum:
                    max_sum = smallest + second_smallest
        return max_sum

# Approach 2: This problem boils down to find a consecutive pair with maximum sum.
# Ref: https://www.geeksforgeeks.org/maximum-sum-of-smallest-and-second-smallest-in-an-array/
class Solution:
    def pairWithMaxSum(self, nums, N):
        nums_size = len(nums)
        max_sum = float("-inf")

        for idx in range(nums_size - 1):
            if max_sum < nums[idx] + nums[idx+1]:
                max_sum = nums[idx] + nums[idx+1]

        return max_sum
    
