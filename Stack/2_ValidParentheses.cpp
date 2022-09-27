// Link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char c : s)
        {
                if(!brackets.empty() && brackets.top() == '(' && c == ')')
                    brackets.pop();
                else if(!brackets.empty() && brackets.top() == '{' && c == '}')
                    brackets.pop();
                else if(!brackets.empty() && brackets.top() == '[' && c == ']')
                    brackets.pop();
                else
                    brackets.push(c);
        }
        return brackets.empty();
    }
};
