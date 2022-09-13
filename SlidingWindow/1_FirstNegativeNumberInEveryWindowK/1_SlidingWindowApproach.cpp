//Link: https://www.codingninjas.com/codestudio/problems/first-negative-in-every-window_759333?leftPanelTab=1
#include <list>
vector<int> firstNegative(vector<int> arr, int n, int k) {
    vector<int> result;
    list<int> negs;
    for(int i=0,j=0; j<n;)
    {
        if(arr[j] < 0)
        {
            negs.push_back(arr[j]);
        }
        
        if(j-i+1<k)
            j++;
        else
        {
            if(negs.size()>0)
            {
                result.push_back(negs.front());
                if(arr[i] == negs.front())
                    negs.pop_front();
            }
            else
            {
                result.push_back(0);
            }
            i++;
            j++;
        }
    }
    return result;
}
