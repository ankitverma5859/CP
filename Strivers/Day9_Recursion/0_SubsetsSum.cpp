// Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
// Powerset method

class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> subsetSum;
        int total_subsets = pow(2, N);
        
        for(int i=0; i<total_subsets; i++){
            int sum = 0;
            for(int j=0; j<N; j++){
                if((i & (1 << j)) != 0){
                    sum += arr[j];
                }
            }
            subsetSum.push_back(sum);
        }
        
        return subsetSum;
    }
};
