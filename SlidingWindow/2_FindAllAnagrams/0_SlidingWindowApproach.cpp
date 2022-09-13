class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        
        int n = s.size();
        int k = p.size();
        unordered_map<char, int> m;
        for(int i=0; i<k; i++)
        {
            m[p[i]]++;
        }
        
        int count = m.size();
        
        int ans;
        for(int i=0, j=0; j<n;)
        {
            if(m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if(m[s[j]] == 0)
                {
                    count--;
                }
            }
            
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                if(count == 0)
                {
                    res.push_back(i);
                    ans++;
                }
                
                if(m.find(s[i]) != m.end())
                {
                    m[s[i]]++;
                    if(m[s[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        
        return res;
    }
};
