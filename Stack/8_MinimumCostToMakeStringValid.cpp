// Link: https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0
// Reference: https://www.youtube.com/watch?v=BmZnJehDzyU&list=PLDzeHZWIZsTrhXYYtx4z8-u8zA-DzuVsj&index=2&ab_channel=CodeHelp-byBabbar
// 1:30

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  int s = str.size();
  
  // If there are odd number of characters that means there is one character for which we cannot find the opposite bracket and hence false;
  if(s%2==1) return -1;

  // Removing all the correct brackets(open and close in order)
  stack<char> stk;
  for(auto c : str){
      if(c == '{'){
          stk.push(c);
      }
      else{
          if(!stk.empty() and stk.top() == '{'){
              stk.pop();
          }
          else{
              stk.push(c);
          }
      }
  }  
  
    
  // Processing the remaining i.e incorrectly used brackets. and with the formula ((a+1)/2) + ((b+1)/2) we find the answer.
  // For more details about the formula watch the video.
  int a=0, b=0;
  while(!stk.empty()){
      if(stk.top() == '{')
          a++;
      else if(stk.top() == '}')
          b++;
      stk.pop();
  }
    
  return ((a+1)/2) + ((b+1)/2); 
}
