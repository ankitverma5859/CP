// Link: https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
void words(string &s, vector<string> &dictionary, int idx, string &curr, vector<string>& result){
    // Base Condition. If the iteration reached the end, break
    if(idx == s.size()){
        result.push_back(curr);
        return;
    }
    
    for(int i=idx; i<s.size(); i++){
        string curr_word = s.substr(idx, i-idx+1);
        
        //Check if the word is present in the dict
        bool isPresent = false;
        for(auto key : dictionary){
            if(key.compare(curr_word) == 0){
                isPresent = true;
                break;
            }
        }
        
        if(isPresent){
            string w = curr;
            curr += curr_word + " ";
            // ** the i+1 here
            words(s, dictionary, i+1, curr, result);
            
            //Backtracking
            curr = w;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> result;
    
    //To track the current result
    string curr;
    
    words(s, dictionary, 0, curr, result);    
    
    return result;
}
