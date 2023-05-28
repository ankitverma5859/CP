'''
https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-if-an-array-is-sorted
'''

# Just checking if (i+1)th element is always greater than ith element or not
#
#
class Solution:
    def arraySortedOrNot(self, arr, n):
        #arr_desc = sorted(arr)
        #return 1 if arr == arr_desc else 0
        
        for idx, item in enumerate(arr):
            if idx+1 < len(arr):
                if arr[idx+1] < arr[idx]:
                    return 0
        return 1
    
    
'''
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/959149912/
'''
class Solution:

    def check(self, nums: List[int]) -> bool:
        # Find rotation index and num_of_rotations = 0
        # if num_of_rotations is more than 1 then it is not sorted rotated
        num_of_rotations = 0
        for idx, item in enumerate(nums):
            if idx+1 < len(nums):
                if nums[idx+1] < nums[idx]:
                    num_of_rotations += 1
                    
        if num_of_rotations > 1:
            return False
        # Corner Case, number of rotations is just 1 i.e first element will never be less than the last element
        elif num_of_rotations == 1 and nums[0] < nums[len(nums)-1]:
            return False
        else:
            return True
