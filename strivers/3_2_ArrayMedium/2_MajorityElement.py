'''
https://leetcode.com/problems/majority-element/description/
Ref: https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/. (Moore's Voting Algorithm)
'''

# Using a hashmap counter
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num_cnts = {}

        for num in nums:
            if num in num_cnts:
                num_cnts[num] += 1
            else:
                num_cnts[num] = 1

        for key, cnt in num_cnts.items():
            if cnt >= len(nums)//2 + 1:
                return key
        
        return -1

# Using Moore's Voting Algorithm
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # Moore's Voting Algorithm

        cnt = 0
        ele = -1

        for num in nums:
            if cnt == 0:
                cnt = 1
                ele = num
            elif num == ele:
                cnt += 1
            elif num != ele:
                cnt -= 1
        
        return ele
