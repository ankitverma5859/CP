'''
https://leetcode.com/problems/move-zeroes/description/
'''

# Approach: Using temporary array
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        non_zero_idx = []
        nums_size = len(nums)

        # Create a list of indexs of non-zero elements
        for itr in range(nums_size):
            if nums[itr] != 0:
                non_zero_idx.append(itr)

        # replace in nums with non-zero elements
        for i in range(len(non_zero_idx)):
            nums[i] = nums[non_zero_idx[i]]
        
        # replace in nums with zero elements
        for i in range(len(non_zero_idx), nums_size):
            nums[i] = 0
            
# Approach: Using two pointers
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        nums_size = len(nums)
        zero_idx = -1
        non_zero_idx = -1

        # Find the first occurance of zero-element
        for i in range(nums_size):
            if nums[i] == 0:
                zero_idx = i
                non_zero_idx = i+1
                break
        
        # No zero elments found
        if zero_idx == -1:
            return
        
        # Swapping zero-element with non-zero element with two pointers
        while non_zero_idx < nums_size:
            if nums[non_zero_idx] != 0:
                nums[zero_idx], nums[non_zero_idx] = nums[non_zero_idx], nums[zero_idx]
                zero_idx += 1
            non_zero_idx += 1
            
