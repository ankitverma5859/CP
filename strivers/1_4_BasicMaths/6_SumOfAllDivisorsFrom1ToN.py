'''
https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

Approach 1: Iterate from 1 to N and find the divisors
'''
class Solution:
    div_sum = {}
    
    def get_divisors_sum(self, num):
        sum_of_divisors = 0
        for i in range(1,num+1):
            if num%i == 0:
                sum_of_divisors += i
        return sum_of_divisors
        
    
    def sumOfDivisors(self, N):
        total_sum = 0
        for i in range(1, N+1):
            divisors_sum = self.get_divisors_sum(i)
            total_sum += divisors_sum

    	return total_sum
    
'''
Approach 2: 
Take Example of 36. Its divisors are:
     ---------------------------------|
     |        --------------          |
     |       |              |         |
     |       |              |         |
     1   2   3   4   6   9  12   18  36
         |       |       |       |  
         |       |       |       |
         |       --------        |     
         ------------------------ 
         
    We observe that (1*36 = 36), (2*18 = 36), (3*12 = 36), (4*9 = 36), and 6(perfect squares-corner case)
    So, we can iterate only till square root of num and find divisors and their complements that when multipled with the divisor gives num.
     
'''
class Solution:
    div_sum = {}
    
    def get_divisors_sum(self, num):
        sum_of_divisors = 0
        for i in range(1, int(num**0.5)+1):
            if num%i == 0:
                sum_of_divisors += i
                
                #corner-case, only add if its not the perfect square
                if i != num/i:
                    j = int(num/i)
                    sum_of_divisors += j

        return sum_of_divisors
        
    
    def sumOfDivisors(self, N):
        total_sum = 0
        
        for i in range(1, N+1):
            divisors_sum = self.get_divisors_sum(i)
            total_sum += divisors_sum
        
    	return total_sum
