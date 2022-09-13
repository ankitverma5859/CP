//Link: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

long maximumSumSubarray(int K, vector<int> &Arr , int N){
    int max_sum = INT_MIN;

    int sum = 0;
  
    //Finding the sum of first K elements
    for(int i=0; i<K ;i++)
    {
        sum += Arr[i];
    }
    max_sum = max(max_sum, sum);

    //Finding the next subarray sums by sliding the window of size K, by adding the next element and 
    //subtracting the first element of the last sum
    for(int i=K; i<N; i++)
    {
        sum = sum + Arr[i] - Arr[i-K];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
