// Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

/*
  We sort both the arr and dep separately. This makes us in the position that
  arr[i] and dep[i] are two different trains. 
  
  Now, if arr[i] <= dep[j] that means train1 has arrived earlier than train2 and hence we need an extra platform.
  However, if arr[i] > dep[j], train1 arrived after train2, so we dont need the extra platform that we already calculated for will be calculating, hence --.
*/
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int i=1, j=0, max_platforms = INT_MIN, curr_plt = 1;
        
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                curr_plt++;
                i++;
            }
            else{
                curr_plt--;
                j++;
            }
            max_platforms = max(max_platforms, curr_plt);
        }
        return max_platforms;
    }
};
