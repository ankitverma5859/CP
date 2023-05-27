'''
https://practice.geeksforgeeks.org/problems/palindrome-string0817/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=palindrome-string
'''

# Recursion
def check_palindrome(s):
    def helper(s, l, r):
        # base condition
        if l >= r:
            return True

        # operation
        if s[l] != s[r]:
            return False 
        else:
            return helper(s, l+1, r-1)
    return helper(s, 0, len(s)-1)

print(check_palindrome(s))

# Iterative
class Solution:
	def isPalindrome(self, s):
        l = 0
        r = len(s) - 1
        result = 1
        while l <= r:
            if s[l] != s[r]:
                result = 0
                break;
            l += 1
            r -= 1
        return result
