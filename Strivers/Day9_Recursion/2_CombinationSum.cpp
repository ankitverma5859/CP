// Link: https://leetcode.com/problems/combination-sum/
// Explanation: https://leetcode.com/problems/combination-sum/discuss/1777334/C%2B%2BorDetailed-Explanation-w-TREE-DIAGRAMor-RECURSION-%2B-BACKTRACKINGor-EACH-STEP-EXPLAINED

class Solution {
public:
    //Creating a global variable to access it directly in the recursion function.
    int target_sum;
    
    //Creating global variable so that it can be updated directly in the recursion function.
    vector<vector<int>> combinations;
    
    void findcombinations(vector<int>& arr, int i, int sum, vector<int> op){
        if(i >= arr.size())
            return;
        
        if(sum + arr[i] == target_sum){
            op.push_back(arr[i]);
            combinations.push_back(op);
            return;
        }
        else if(sum + arr[i] < target_sum){
            //Creating two vector with the current elements
            vector<int> op1 = op;
            vector<int> op2 = op;
            
            //Left recursion taking same element
            //Since we are considering arr[i] we push it.
            op2.push_back(arr[i]);
            findcombinations(arr, i, sum + arr[i], op2); 
            
            //Right recursion moving forward
            findcombinations(arr, i+1, sum, op1);
        }
        else{
            findcombinations(arr, i+1, sum, op);
        }
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        target_sum = target;
        vector<int> op;
        sort(candidates.begin(), candidates.end());
        findcombinations(candidates, 0, 0, op);
        return combinations;
    }
};
