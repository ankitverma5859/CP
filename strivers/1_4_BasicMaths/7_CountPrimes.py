'''
https://leetcode.com/problems/count-primes/description/
'''

class Solution:
    def countPrimes(self, n: int) -> int:
        # Sieve of Eratosthenes
        is_prime = [True for i in range(n)]
        
        size_is_prime = len(is_prime)
        if size_is_prime >= 1:
            is_prime[0] = False
            if size_is_prime >= 2:
                is_prime[1] = False
        
        for i in range(2, int(n**0.5)+1):
            if is_prime[i]:
                j = 2
                while i*j < n:
                    is_prime[i*j] = False
                    j+= 1
        
        cnt = 0
        for i in range(n):
            if is_prime[i] == True:
                cnt += 1

        return cnt
