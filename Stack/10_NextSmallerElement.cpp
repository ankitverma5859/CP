//Link: https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> res(n);
    
    stack<int> s;
    s.push(-1);
    
    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        
        while(s.top() >= curr)
            s.pop();
        
        res[i] = s.top();
        
        s.push(curr);
    }
    return res;
}
