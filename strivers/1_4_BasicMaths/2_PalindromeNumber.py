'''
https://leetcode.com/problems/palindrome-number/description/

Approach1: Reverse the number and then check if the original number == reversed number
Approach2: Convert the number to string and use two-pointer from both the ends.
'''

class Solution:
    def isPalindrome(self, x: int) -> bool:
        num = str(x)
        
        start = 0
        end = len(num) - 1
        isPalindrome = True

        while start <= end:
            if num[start] != num[end]:
                isPalindrome = False
                break
            start += 1
            end -= 1

        return isPalindrome
