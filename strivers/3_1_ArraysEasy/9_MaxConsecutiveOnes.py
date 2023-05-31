'''
https://leetcode.com/problems/max-consecutive-ones/
'''

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        curr_ones_count = 0
        max_ones_count = 0

        for num in nums:
            if num == 1:
                curr_ones_count += 1
            else:
                if max_ones_count < curr_ones_count:
                    max_ones_count = curr_ones_count
                curr_ones_count = 0
        
        # Corner case for the last sequence being 1s
        max_ones_count = curr_ones_count if max_ones_count < curr_ones_count else max_ones_count
        return max_ones_count
