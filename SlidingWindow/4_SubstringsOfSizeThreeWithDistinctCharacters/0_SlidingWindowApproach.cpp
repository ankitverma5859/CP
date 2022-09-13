//Link: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int k = 3;
        int cnt = 0;
        int dup_cnt = 0;
        
        unordered_map<char, int> m;
        
        for(int i=0, j=0; j<n;)
        {
            m[s[j]]++;
            if((m.find(s[j]) != m.end()) and (m[s[j]] == 2))
            {
                dup_cnt++;
            }
            
            if(j-i+1 < k)
                j++;
            else
            {
                if(dup_cnt == 0)
                {
                    cnt++;
                }
                    
                m[s[i]]--;
                if(m[s[i]] == 1)
                    dup_cnt--;
                i++;
                j++;
            }
        }
        return cnt;
    }
};

//Simple Solution fron Leetcode Discussion
/*
class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3)return 0;
        char a=s[0],b=s[1],c=s[2];
        int res=0;
        for(int i=3;i<=s.size()-1;i++)
        {
            if(a!=b and b!=c and c!=a)res++;
            a=b;
            b=c;
            c=s[i];
        }
        if(a!=b and b!=c and c!=a)res++;
        return res;
    }
};
*/
