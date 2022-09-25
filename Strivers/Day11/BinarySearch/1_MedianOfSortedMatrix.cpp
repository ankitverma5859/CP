// Link: https://www.interviewbit.com/problems/matrix-median/
#define ll long long

ll count_ele(ll ele, vector<int> &A){
    return upper_bound(A.begin(), A.end(), ele) - A.begin();
}

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int k = (n*m) / 2;
    
    ll low = 1;
    ll high = 1000000000000;
    ll ans = 10000000000000;
    while(low <= high){
        ll mid = (low+high) >> 1;
        ll cnt = 0;
        for(int i=0; i<n; i++)
        {
            cnt += count_ele(mid, A[i]);    
        }
        
        if(cnt > k){
            ans = min(ans, mid);
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
