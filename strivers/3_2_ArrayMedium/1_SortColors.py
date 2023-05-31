'''

Approach1: Sort the list
Approach2: Count the number of 0s, 1s, and 2s and replace in the array
Approach3: Dutch National flag Problem Solution
'''

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        '''
        00000000000000 1111111111111111 [xxxxxxxxxxxxxxx] 2222222222
        start low-1.   low        mid-1 [mid        high] high+1   n-1
        '''

        low = 0
        mid = 0
        high = len(nums) - 1

        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            elif nums[mid] == 2:
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1






