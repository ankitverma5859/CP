// Link: https://leetcode.com/problems/reverse-string/

class Solution {
private:
public:
    void reverseString(vector<char>& s) {
        stack<char> str;
        for(char c : s)
            str.push(c);
        
        for(int i=0; i<s.size(); i++){
            s[i] = str.top();
            str.pop();
        }
    }
};
