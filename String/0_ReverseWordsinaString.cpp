//Link: https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        int len = s.size();
        for(int i=0; i<len; i++){
            if(s[i] == ' ') continue;
            
            string word = "";
            while(i < len and s[i] != ' '){
                word += s[i];
                i++;
            }
            words.push(word);
        }
        
        string res = "";
        while(!words.empty()){
            res += words.top();
            if(words.size() != 1)
                res += " ";
            words.pop();
        }
        return res;
    }
};
