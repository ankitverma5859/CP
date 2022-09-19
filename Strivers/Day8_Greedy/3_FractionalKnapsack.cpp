// Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// Sort the array based upon ration of value/weight.
// Fill the knapsack with the large values provided knapsack weight <= MAX_WEIGHT i.e W
// Fill the breaking the element and fill the remaining knapsack.
// Ref: https://www.youtube.com/watch?v=F_DDzYnxO14&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=50&ab_channel=takeUforward


struct Item{
    int value;
    int weight;
};

class Solution
{
    bool static cmp(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, cmp);
        
        
        int curr_weight = 0;
        double profit = 0.0;
        
        for(int i=0; i<n; i++){
            if(curr_weight + arr[i].weight <= W){
                curr_weight += arr[i].weight;
                profit += arr[i].value;
            }
            else{
                int remaining_weight = W - curr_weight;
                double val_for_one = (double)arr[i].value / (double)arr[i].weight;
                profit += (remaining_weight * val_for_one);
                break;
            }
        }
        
        return profit;
    }
        
};
