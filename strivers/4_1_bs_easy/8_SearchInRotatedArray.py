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
                    
                    
# Only one binary search.
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while l <= r:
            mid = (l+r)//2
            if nums[mid] == target:
                return mid

            # At any midpoint either the left part is sorted or the right part is sorted. We search in the sorted part

            if nums[l] <= nums[mid]: # left part is sorted
                if target >= nums[l] and target <= nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else: # right part is sorted
                if target >= nums[mid] and target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1
