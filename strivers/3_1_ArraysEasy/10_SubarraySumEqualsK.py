'''
https://leetcode.com/problems/subarray-sum-equals-k/description/
'''

# Naive Approach
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        nums_size = len(nums)
        total_subarrays_cnt = 0

        for i in range(nums_size):
            total_sum = 0
            for j in range(i, nums_size):
                total_sum += nums[j]
                if total_sum == k:
                    total_subarrays_cnt += 1
                    break
        
        return total_subarrays_cnt
      
      
# Optimal Solution
# Ref: https://www.youtube.com/watch?v=fFVZt-6sgyo&ab_channel=NeetCode
'''
We take help of prefix sum to create a optimal solution. 
We store the count of prefix sums in a hash-map.

Logic: At any point if we find [curr_prefix_sum - k] in the hash map we consider it in our result count.
Intuition: Lets say our k = 3, curr_prefix_sum = 5, so curr_prefix_sum - k = 2, 
if we had prefixes of 2 earlier those subarrays  could be subtracted and we get k, hence we consider the count 
of curr_prefix_sum - k

Edge Case:
       -----------
arr = [1, -1, 1, 1, 1, 1] , k = 3
       --- {"1 : 1"}                                {prefix_sum : cnt}
       ------{"1 : 1", "0 : 1"}
       ----------{"1 : 0", "0 : 1", "2 : 1"}
       --------------{"1 : 1", "0 : 1", "2 : 1", "3 : 1"} 
                     Here, curr_prefix_sum = 3 and if we find curr_prefix_sum - k i.e 3 - 3 = 0, it has a count of just 1(second key in hashmap) 
                     But {1, -1, 1, 1, 1} : k = 3
                                {1, 1, 1} : k = 3
                                both these subarrays have sum = 3
                     so, by default we always have to initialize the hashmap with {0: 1}, 0 prefix_sum with 1 count
                     Hence:
                     {"1 : 1", "0 : 2", "2 : 1", "3 : 1"}
       

'''
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_cnt = {0:1}
        res = 0

        curr_prefix_sum = 0
        for num in nums:
            curr_prefix_sum += num
            # If the curr_prefix_sum - k exists in the hashmap consider its count in the result.
            if  curr_prefix_sum - k in prefix_cnt:
                res += prefix_cnt[curr_prefix_sum - k]
            
            # Storing the prefix_sum counts
            if curr_prefix_sum in prefix_cnt:
                prefix_cnt[curr_prefix_sum] += 1
            else:
                prefix_cnt[curr_prefix_sum] = 1
        return res
