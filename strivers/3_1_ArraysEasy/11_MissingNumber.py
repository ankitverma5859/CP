'''
https://practice.geeksforgeeks.org/problems/missing-number4257/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=missing-number
'''
def missingNumber( A, N):
     actual_sum = sum(A)
     total_sum = (N*(N+1))//2
     
     return total_sum - actual_sum
