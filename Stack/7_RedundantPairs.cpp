// Link: https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=1

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(char c : s){
        // Push a character if it is open bracker or any operator
        if(c == '(' || c == '+' || c == '-' || c == '/' || c == '*'){
            st.push(c);
        }
        else{
            // If we find any closing bracket then we have to check whether there is a operator between this closing brakcet and open bracket or not
            // If there no operator then it is redundant
            if(c == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        isRedundant = false;
                    }
                    // Popping the operators, useful when multiple operators are there between two brackets.
                    st.pop();
                }
                
                if(isRedundant){
                    return true;
                }
                // Popping the opening bracket
                st.pop();
            }
        }
    }
    return false;
}
