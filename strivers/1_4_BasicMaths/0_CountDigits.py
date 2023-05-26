'''
https://practice.geeksforgeeks.org/problems/count-digits5716/1

Approach1: Create a list of all the digits of the number and then check if the number is divisible by each item in the list.
Approach2: Convert the number to a string, take two pointers from both the ends of the string, and check digits from both ends in each iteration.
'''

class Solution:
    def evenlyDivides (self, N):
        nums = []
        n = str(N)
        start = 0
        end = len(n) - 1
        
        cnt = 0
        while start <= end:
            s_num = int(n[start])
            e_num = int(n[end])

            if start == end and s_num != 0 and N % s_num == 0:
                cnt += 1
                break
            
            if s_num != 0 and N % s_num == 0:
                cnt += 1
            
            if e_num != 0 and N % e_num == 0:
                cnt += 1
            start += 1
            end -= 1
            
        return cnt
