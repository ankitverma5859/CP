// Link: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.size();
        int i=0, j=0;
        int result = -1;
        map<char, int> m;
        
        while(j<n){
            m[s[j]]++;
            
            if(m.size() < k)
            {
                j++;
            }
            else if(m.size() == k){
                result = max(result, j-i+1);
                j++;
            }
            else if(m.size() > k){
                while(m.size() > k)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            
        }
        
        
        return result;
    }
};
