//Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    bool static cmp(Job j1, Job j2){
        return j1.profit > j2.profit;
    }
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //Sort the ds(struct of jobs) in descending order on the profit, 
        //because we are maximizing the profit
        sort(arr, arr+n, cmp);
        
        //Find the maximum deadline number to create the block array
        int max_dead = INT_MIN;
        for(int i=0; i<n; i++)
            max_dead = max(max_dead, arr[i].dead);
        
        // This helps us to find out which deadlines are already taken
        vector<int> block(max_dead + 1, -1);
        
        int nj = 0;
        int profit = 0;
        
        for(int i=0; i<n; i++){
            // We are tracing from the back to fill the last deadlines first.(Refer: Strivers Video for more info)
            for(int j=arr[i].dead; j>0; j--){
                if(block[j] == -1){
                    block[j] = i; //string i if we need to provide the sequence of the jobs scheduled
                    nj++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> res;
        res.push_back(nj);
        res.push_back(profit);
        return res;
    } 
};
