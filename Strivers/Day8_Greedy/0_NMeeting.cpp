// Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
/*
    Approach: Select the meeting which ends first.
    Create a vector/struct to store start_time, end_time, and the index;
    Sort ds by the end time, if end time is equal then by the postion in ascending order.
    Pick the meetings if start of current is greater than prev_end_time.
*/
class Solution
{
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    public:
    bool static cmp(struct meeting m1, struct meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        return false;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int result = 1;
        struct meeting meet[n];
        for(long i=0; i<n; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }
        
        sort(meet, meet + n, cmp);
        
        int prev_end = meet[0].end;

        for(int i=1; i<n; i++){
            if(meet[i].start > prev_end){
                result++;
                prev_end = meet[i].end;
            }    
        }
        
        return result;
    }
};
