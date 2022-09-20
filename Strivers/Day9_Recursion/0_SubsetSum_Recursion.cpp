// Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
/*
  Intuition: https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53&ab_channel=takeUforward
  _ _ _
  2 1 0
  Recurse for the position -> take the position or do not take for the sum.
*/

class Solution
{
public:
    void findsubset(int index, int sum, int N, vector<int>& arr, vector<int>& subsetSum){
        if(index == N){
            subsetSum.push_back(sum);
            return;
        }
        
        //Pick the element
        findsubset(index+1, sum + arr[index], N, arr, subsetSum);
        
        //Do not pick the element
        findsubset(index+1, sum, N, arr, subsetSum);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> subsetSum;
        int index = 0, sum = 0;
        findsubset(index, sum, N, arr, subsetSum);
        sort(subsetSum.begin(), subsetSum.end());
        return subsetSum;
    }
};

