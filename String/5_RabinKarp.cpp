//Link: https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1
/*
Rabin Karp:
In a naive approach, we match every window with the pattern string.
In RK, we calculate the hash of each window, and the pattern. We match the window and the only if the hash values match.
       Hash can be computed in O(1) and hence it is a better solution. 
       
       Challenge is to find the hash of new window efficiently, i.e with hash of prev window, and the new character.
       
       h_new = (d(h_old - prev_c*h) + new_c)%q;
               d = 256 Number of characters
               h = pow(d, m-1), m is number of characters in pattern
               q = A prime number to avoid overflow from the int.

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> res;
            
            
            int n = txt.size();
            int m = pat.size();
            
            //If pattern length is larger than the text length
            if(n < m){
                res.push_back(-1);
                return res;
            }
            
            
            // This is heart of the algo
            //h_new = (d(h_old - f_c*h) + n_c) % q;
                    //f_c : first_char
                    //n_c : new_char
            //h = pow(d, m-1)
            //d  256                // number of characters
            //q = [any prime number, larger the better] 
            
            
            const int d = 256;
            int q = 101;
            int h = 1;
            
            //Calculating the value of h
            for(int i=0; i<m-1; i++){
                h = (h*d)%q;
            }
            
            //Calculating the first hashes
            int p = 0;      //hash value of pattern
            int t = 0;      //hash value of text
            
            for(int i=0; i<m; i++){
                // (d*h_old + n_c)%q;
                t = (d*t + txt[i])%q;
                p = (d*p + pat[i])%q;
            }
            
            int j;
            for(int i=0; i<=n-m; i++){
                //If hashes match compare the text
                if(p==t){
                    //Check for characters
                    for(j=0; j<m; j++){
                        if(txt[i+j] != pat[j]){
                            break;
                        }
                    }
                    
                    if(j==m)
                        res.push_back(i+1);
                }
                
                // Calculating hash for next window
                if(i < n-m){
                    //Calculate new hash
                    t = (d*(t - txt[i]*h) + txt[i+m])%q;
                    
                    //If t is negative.
                    if(t < 0)
                        t += q;
                }
            }
            
            if(res.size() == 0)
                res.push_back(-1);
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
