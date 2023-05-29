'''
https://leetcode.com/problems/rotate-array/description/
'''

# Approach: Rotate the array k times
# Not efficient
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums_size = len(nums)

        k %= nums_size
        
        # Rotate by k 
        for itr in range(k):
            # Rotate by 1 
            temp = nums[nums_size - 1]
            for i in range(nums_size-1, 0, -1):
                nums[i] = nums[i-1]
            nums[0] = temp 

        return
    
# Approach : Using temp array
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums_size = len(nums)
        k %= nums_size

        # Storing the last k elements in temp because they need to to right
        # rotated i.e moved in the start of the array
        temp = []
        for i in range(nums_size - k, nums_size):
            temp.append(nums[i])
        
        # moving the 0 - k elements to the last
        for i in range(nums_size - k - 1, -1, -1):
            nums[i+k] = nums[i]

        # replacing the first k values in nums from temp
        for i in range(k):
            nums[i] = temp[i]

        return

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
