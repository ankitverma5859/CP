'''
https://leetcode.com/problems/subarray-sum-equals-k/description/
'''

# Naive Approach
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        nums_size = len(nums)
        total_subarrays_cnt = 0

        for i in range(nums_size):
            total_sum = 0
            for j in range(i, nums_size):
                total_sum += nums[j]
                if total_sum == k:
                    total_subarrays_cnt += 1
                    break
        
        return total_subarrays_cnt
      
      
# Optimal Solution
