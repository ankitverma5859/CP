//Link: https://www.codingninjas.com/codestudio/problems/first-negative-in-every-window_759333?leftPanelTab=1

vector<int> firstNegative(vector<int> arr, int n, int k) {
    vector<int> first_negs;
    for(int i=0; i<n-k+1; i++)
    {
        bool has_neg = false;
        int neg_count = 0;
        for(int j=i; j<i+k; j++)
        {
            if(arr[j] < 0 and neg_count < 1)
            {
                has_neg = true;
                neg_count++;
                cout<<arr[j]<<" ";
                break;
            }
                
        }
        if(!has_neg)
            cout<<0<<" ";
    }
    return first_negs;
}
