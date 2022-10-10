//Link: https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
     vector<pair<int, string>> m = {
         {1000, "M"},
         {900, "CM"},
         {500, "D"},
         {400, "CD"},
         {100, "C"},
         {90, "XC"},
         {50, "L"},
         {40, "XL"},
         {10, "X"},
         {9, "IX"},
         {5, "V"},
         {4, "IV"},
         {1, "I"}
     };
    
    int len = m.size();
    string res = "";
    for(int i=0; i<len;){
        if(num - m[i].first >= 0){
            num -= m[i].first;
            res += m[i].second;
        }
        else
            i++;
    }
    return res;
    }
};
