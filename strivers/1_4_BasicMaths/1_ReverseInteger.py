'''
https://leetcode.com/problems/reverse-integer/submissions/957804635/
'''
class Solution:
    def reverse(self, x: int) -> int:
        
        is_neg_int = False
        if x < 0:
            is_neg_int = True
            x *= -1
        
        res = 0
        l = len(str(x))
        
        while x > 0:
            rem = x % 10
            x = int(x / 10)
            res += rem*(10**(l-1))
            l -= 1

        if res < -(2**31) or res > (2**31)-1:
            return 0
        
        return res if not is_neg_int else -1*res
        

        
        
