'''
https://leetcode.com/problems/find-peak-element/submissions/963391566/
'''

# Time Complexity: O(n)
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        peak_element_idx = -1
        nums_len = len(nums)
        
        if nums_len == 1:
            return 0


        for idx in range(1, nums_len - 1):
            if nums[idx] > nums[idx-1] and nums[idx] > nums[idx+1]:
                peak_element_idx = idx
                break
        
        if peak_element_idx == -1:
            # Check for fist element
            if nums[0] > nums[1]:
                peak_element_idx = 0
            elif nums[len(nums)-1] > nums[len(nums)-2]:
                peak_element_idx = len(nums)-1

        return peak_element_idx
    
# Time Complexity: O(logn)
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        nums_len = len(nums)
        
        # If the list as only one element
        if nums_len == 1:
            return 0

        # Binary Search: following the larger element
        l = 0
        r = nums_len - 1
        while l < r:
            mid = (l+r)//2
            
            # Check if first element is the peak element
            if mid == 0:
                return 0 if nums[0] > nums[1] else 1

            # Check if last element is the peak element
            if mid == nums_len - 1:
                return  nums_len-1 if nums[nums_len-1] > nums[nums_len - 2] else nums_len - 2

            if nums[mid] >= nums[mid-1] and nums[mid] >= nums[mid+1]:
                return mid
            
            if nums[mid] < nums[mid-1]:
                r = mid - 1
            else:
                l = mid + 1

        return l # or start index
