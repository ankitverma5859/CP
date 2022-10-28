//Link: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        
        
        sort(strs.begin(), strs.end());
        
        string f = strs[0];         // First String(largest) in string vector
        string l = strs[n-1];       // Last String(smallest) in string vector
        
        string ans = "";
        for(int i=0; i<f.size(); i++){
            if(f[i] == l[i]){
                ans += f[i];
            }else{
                break;
            }
        }
        
        return ans;
    }
};
