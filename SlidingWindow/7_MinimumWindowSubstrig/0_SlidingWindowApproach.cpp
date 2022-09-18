//Link: https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int k = t.size();
        
        /*
            Conditions to return empty string.
        */
        if(n == 0 or k == 0 or n < k)
            return "";
        
        map<char, int> m;
        int result = INT_MAX;
        pair<int, int> res_index;
        res_index.first = -1;
        res_index.second = -1;
        
        for(int i= 0; i<t.size(); i++)
            m[t[i]]++;
        
        int count = m.size();
        int i=0,j=0;
        while(j<n){
            //Calculation
            if(m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if(m[s[j]] == 0)
                    count --;
            }
            
            if(count == 0){
                while(count == 0){
                    int r = result;
                    result = min(result, j-i+1);
                    if(r != result){
                        res_index.first = i;
                        res_index.second = j;    
                    }
                    
                    if(m.find(s[i]) == m.end())
                        i++;
                    else{
                        cout<<s[j]<<" ";
                        m[s[i]]++;
                        if(m[s[i]] > 0)
                            count++;
                        i++;
                    }
                }
            }
            
            j++;    
        }
        string r1 = "";
        
        /*
            For cases like s = "a" and t ="b" the res_index will now change and the 
            below condition to return empty string for it.
        */
        if(res_index.first != -1)
        {
            for(int i=res_index.first; i<=res_index.second; i++)
            r1 += s[i];    
        }
        
        return r1;
    }
};
