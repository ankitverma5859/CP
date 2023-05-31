'''
https://leetcode.com/problems/maximum-subarray/description/
Kadane Algorithm
'''

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_so_far = 0
        current_sum = 0

        for num in nums:
            current_sum += num

            if max_so_far < current_sum:
                max_so_far = current_sum

            if current_sum < 0:
                current_sum = 0

        return max_so_far
