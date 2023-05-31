'''
https://leetcode.com/problems/missing-number/
'''

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums_size = len(nums)
        actual_sum = sum(nums)
        total_sum = (nums_size*(nums_size+1))//2

        return total_sum - actual_sum
