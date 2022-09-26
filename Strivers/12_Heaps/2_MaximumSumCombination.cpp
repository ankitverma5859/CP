// Link: https://www.interviewbit.com/problems/maximum-sum-combinations/
// Reference: https://www.youtube.com/watch?v=yNLu2kJUjjU&ab_channel=HimanshuTripathi
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    
    priority_queue<pair<int, pair<int,int>>> pq;
    set<pair<int, int>> s;
    
    pq.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    s.insert(make_pair(n-1, n-1));
    
    vector<int> res;
    while(C--){
        auto top = pq.top();
        pq.pop();
        
        res.push_back(top.first);
        
        int L = top.second.first;
        int R = top.second.second;
        
        if(L!=0 and R!=0 and s.find(make_pair(L-1, R)) == s.end()){
            pq.push(make_pair(A[L-1]+B[R], make_pair(L-1, R)));
            s.insert(make_pair(L-1, R));
        }
        
        if(L!=0 and R!=0 and s.find(make_pair(L, R-1)) == s.end()){
            pq.push(make_pair(A[L]+B[R-1], make_pair(L, R-1)));
            s.insert(make_pair(L, R-1));
        }
    }
    
    
    return res;
}
