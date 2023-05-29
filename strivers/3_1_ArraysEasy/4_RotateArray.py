'''

'''
# Approach: Using Slicing
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums_size = len(nums)
        
        # Corner-case
        # Return the same array coz 0 rotations or if there is only one element in the array
        if k == 0 or nums_size == 1:
            return

        # reduce the k rotations within the nums_size limits
        if k > nums_size:
            k %= nums_size

        nums[:] = nums[-k:] + nums[:nums_size-k]
        return
