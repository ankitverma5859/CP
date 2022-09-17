// Link: https://leetcode.com/problems/fruit-into-baskets/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        
        
            
        int k = 2;
        map<int, int> m;
        int result = INT_MIN;
        int i=0, j=0;
        
        if(n <= k)
            return n;
        
        while(j<n){
            m[fruits[j]]++;    
            if(m.size() < k)
                j++;
            else if(m.size() == k){
                result = max(result, j-i+1);
                j++;
            }
            else if(m.size() > k){
                while(m.size() > k){
                    m[fruits[i]]--;
                    if(m[fruits[i]] == 0)
                        m.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        
        return result;
    }
};
