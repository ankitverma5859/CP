//Link: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

long maximumSumSubarray(int K, vector<int> &Arr , int N){
    int max_sum = INT_MIN;
    for(int i=0; i<N-K+1; i++)
    {
        int sum = 0;
        for(int j=i; j<i+K; j++)
        {
            sum+=Arr[j];
        }
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
