//Link: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        
        bool result = false;
        
        map<char, int> m;
        
        for(int i=0; i<k ;i++)
        {
            m[s1[i]]++;
        }
        int count = m.size();
        
        for(int i=0, j=0; j<n;)
        {
            //Calculation
            if(m.find(s2[j]) != m.end())
            {
                m[s2[j]]--;
                if(m[s2[j]] == 0)
                    count--;
            }
            
            if(j-i+1 < k)
                j++;
            else
            {
                if(count == 0)
                {
                    result = true;
                    break;
                }
                else
                {
                    if(m.find(s2[i]) != m.end())
                    {
                        m[s2[i]]++;
                        if(m[s2[i]] == 1)
                            count++;
                    }
                }
                i++;
                j++;
                    
            }
        }
        
        return result;
    }
};
