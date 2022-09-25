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

/*
class Solution{
    public:
    long long count_element(long long ele, int arr[], int s){
        long long low = 0;
        long long high = s-1;
        
         while(low <= high){
             long long mid = (low+high) >> 1;
             //cout<<"M: "<<mid<<endl;
             if(arr[mid] <= ele){
                 low = mid + 1;
             }
             else
                high = mid - 1;
         }
         return high+1;         
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
     long long low = min(arr1[0], arr2[0]);
     long long high = max(arr1[n-1], arr2[m-1]);
     while(low <= high){
         long long mid = (low+high) >> 1;
         long long cnt = count_element(mid, arr1, n) + count_element(mid, arr2, m);
         //cout<<"C: "<<cnt<<endl;
         if(cnt <= k-1){
             low = mid + 1;
         }
         else
            high = mid - 1;
     }
     return low;   
    }
};
*/
