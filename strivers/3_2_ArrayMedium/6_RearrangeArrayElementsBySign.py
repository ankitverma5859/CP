'''
https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
'''

#User function Template for python3
from collections import deque

class Solution:
    def rearrange(self,nums, n):
        queue_pos = deque([])
        queue_neg = deque([])
        
        for num in nums:
            if num < 0:
                queue_neg.append(num)
            else:
                queue_pos.append(num)
                
        
        for idx in range(len(nums)):
            has_pos = len(queue_pos)
            has_neg = len(queue_neg)
            
            if has_pos and has_neg:
                if idx%2==0:
                    nums[idx] = queue_pos.popleft()  
                else:
                    nums[idx] = queue_neg.popleft()
            elif has_pos:
                nums[idx] = queue_pos.popleft()
            elif has_neg:
                nums[idx] = queue_neg.popleft()
                
        return nums
                
# Approach 2: Without using extra space
# First find the index with a wrong sign value, then find and index with the opposite sign value, and then rotate, repeat until you find indexes 
# with wrong sign value

# Ref: https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

