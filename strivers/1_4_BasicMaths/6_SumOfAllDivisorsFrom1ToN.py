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
    
'''
Approach 3:
Take Example of 6:
F(6) + F(5) + F(4) + F(3) + F(2) + F(1)

F(6) = 1 * 2 * 3 * 6
F(5) = 1 * 5
F(4) = 1 * 2 * 4
F(3) = 1 * 3
F(2) = 1 * 2
F(1) = 1

Basicall, In the total_sum, 1 appears 6x, 2 appears 3x, 3 appears 2x, 4 appears 1x, 5 appears 1x, 6 appears 1x
sum =  (6*1)     +     (3*2)      +     (2*3)      +     (1*4)     +     (1*5)   +    (6/6)*1   
      (6/1)*1         (6/2)*2          (6/3)*3          (6/4)*4        (6/5)*6.       (6/6)*6
      
      

i = 1 to N
    (N/i)*i
'''
class Solution:

    def sumOfDivisors(self, N):
        total_sum = 0
        
        for i in range(1, N+1):
            total_sum += int(N/i)*i
        
    	return total_sum




