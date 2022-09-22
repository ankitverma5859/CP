//Link: https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> arr(n, 0);
        int idx = 1;
        for(int i=0; i<n; i++){
            arr[i] = idx;
            idx++;
        }
        
        for(int i=0; i<k-1; i++)
            next_permutation(arr.begin(), arr.end());
        
        string s = "";
        for(int i=0; i<n;i++)
            s += to_string(arr[i]);
        
        return s;
    }
};
