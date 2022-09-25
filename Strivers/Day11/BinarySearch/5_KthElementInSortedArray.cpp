// Link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
class Solution{
    public:
    long long count_element(long long mid, int arr[], int s){
        return upper_bound(arr, arr+s, mid) - arr;
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
     long long low = 1;
     long long high = 100000000000;
     long long ans = 100000000000;
     while(low <= high){
         long long mid = (low+high) >> 1;
         long long cnt = count_element(mid, arr1, n) + count_element(mid, arr2, m);
         if(cnt >= k){
             ans = min(ans, mid);
             high = mid -1;
         }
         else
            low = mid + 1;
     }
     return ans;   
    }
};
