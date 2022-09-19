// Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
  
    //Approach is to find the max number of overlapping trians for each train and then take the max out of them.
    //Drawing the line diagram helps to visually understand the problem.
    int findPlatform(int arr[], int dep[], int n)
    {
        int max_overlap = INT_MIN;
        for(int i=0; i<n; i++){
            int curr_overlap = 1;
    	    for(int j=0; j<n; j++){
    	        if(i != j)
    	        {
    	            if(arr[i] >= arr[j] && arr[i] <= dep[j])
    	                curr_overlap++;
    	        }
    	    }
    	    max_overlap = max(max_overlap, curr_overlap);
    	}
    	return max_overlap;
    }
};

