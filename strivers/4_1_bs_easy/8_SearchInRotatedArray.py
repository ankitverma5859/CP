'''
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
'''

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Find the peak element with BS
        # [BS in 0 - peak element], BS in []peak elemen - len]

        def binary_search(nums, l, r, target):
            while l <= r:
                mid = (l+r)//2
                if nums[mid] == target:
                    return mid
                elif target < nums[mid]:
                    r = mid - 1
                elif target > nums[mid]:
                    l = mid + 1
            return -1

        def find_peak_index(nums):
            l, r = 0, len(nums) - 1
            
            # You will find the peak index where the value at the index is smaller then the previous index. Why, both the sorted subarrays divided by the peak index are in increasing order
            while l <= r:
                mid = (l+r)//2
                if mid-1 >= 0 and nums[mid] < nums[mid-1]:
                    return mid
                elif nums[mid] >= nums[r]: # rightmost element 
                    l = mid + 1
                else:
                    r = mid - 1

            return -1

        peak_index = find_peak_index(nums)
        if peak_index == -1:  # no peak index, i.e no rotation, hence search in all
            return binary_search(nums, 0, len(nums) - 1, target)
        else:
            if target >= nums[peak_index] and target <= nums[len(nums) - 1]:
                return binary_search(nums, peak_index, len(nums)-1, target)
            else:
                return binary_search(nums, 0, peak_index - 1, target)
