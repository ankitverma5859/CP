//Link: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
/*
How to identify if a problem is of Sliding Window?
1) Given    :     array/string
2) To find  :     subarray/substring            (of window size K)
3) Which is :     largest/maximum/least etc

There are two types of Sliding Window Problems:
1) Fixed Size Window Problems(K is given) to find maximum sum, etc.
2) Variable Size Window Problems(K is not give, sum or some fixed parameter is given). and find the maximum/minimum length of subarray/substring.
*/

long maximumSumSubarray(int K, vector<int> &Arr , int N){
    long long max_sum = INT_MIN;

    long long sum = 0;
    for(int i=0,j=0; j<N;)
    {
        sum += Arr[j];
        if(j-i+1<K)
            j++;
        else
        {
            max_sum = max(max_sum, sum);
            sum = sum - Arr[i];
            j++;
            i++;
        }
    }

    return max_sum;
}

/*
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
*/
