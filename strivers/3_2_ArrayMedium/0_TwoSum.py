'''
https://leetcode.com/problems/two-sum/description/
'''

# Naive
# O(n^2)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = []
        for idx1, num in enumerate(nums):
            complement = target - num
            for idx2 in range(idx1+1, len(nums)):
                if nums[idx2] == complement:
                    res.extend([idx1, idx2])
                    break
        
        return res
      
# Better
# Using Hashmap : O(n)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = []
        
        hash_map = {}

        for idx, num in enumerate(nums):
            complement = target - num
            if complement in hash_map:                        # this can be a costly operatin in some cases
                res.extend([hash_map[complement], idx])
                break
            else:
                hash_map[num] = idx

        return res
