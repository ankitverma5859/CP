'''
https://leetcode.com/problems/single-number/
'''
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        num_cnt = {}
        for num in nums:
            if num in num_cnt:
                num_cnt[num] += 1
            else:
                num_cnt[num] = 1
        
        res = -1
        for key, val in num_cnt.items():
            if val == 1:
                res = key
                break;

        return res
