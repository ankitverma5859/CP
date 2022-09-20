// Link: https://www.codingninjas.com/codestudio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
/*
  Approach as as N meetings room.
*/
struct activities{
    int start;
    int end; 
    int pos;
};

bool static cmp(struct activities a, struct activities b){
    return a.end < b.end;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int s = start.size();
    struct activities a[s];
    for(int i=0; i<start.size(); i++)
    {
        a[i].start = start[i];
        a[i].end = finish[i]; 
        a[i].pos = i;
    }
    
    sort(a, a+s, cmp);
    
    int n = 1;
    int prev_end = a[0].end;
    for(int i=1; i<s; i++){
        if(a[i].start >= prev_end){
            n++;
            prev_end = a[i].end;
        }
    }    
    return n;    
}
