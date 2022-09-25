// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/
#define ll long long
class Solution {
public:
    ll count_nums(vector<int> &nums, int ele){
        return upper_bound(nums.begin(), nums.end(), ele) - nums.begin();
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        ll m = nums2.size();
        ll low = 0;
        if(n > 0 and m > 0)
            low = min(nums1[0], nums2[0]);
        else if(n == 0)
            low = min(0, nums2[0]);
        else if(m == 0)
            low = min(nums1[0], 0);
        ll high = 1000000;
        double ans = 10000000;
        double ans1 = 1000000;
        double ans2 = 1000000;
        ll k1 = (n+m) / 2;
        ll k2 = ((n+m) / 2) + 1;
        if((n+m) % 2 == 0){
            cout<<"Hello"<<endl;
            //Even
            //Find kth and k+1 the average
            while(low <= high){
                double mid = (low+high) >> 1;
                double cnt = count_nums(nums1, mid) + count_nums(nums2, mid);
                if(cnt >= k1){
                    ans1 = min(ans1, mid);
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            } 
                        

            low = 0;
            if(n > 0 and m > 0)
                low = min(nums1[0], nums2[0]);
            else if(n == 0)
                low = min(0, nums2[0]);
            else if(m == 0)
            low = min(nums1[0], 0);
            high = 10000000;
            ans2 = 100000000;
            while(low <= high){
                double mid = (low+high) >> 1;
                double cnt = count_nums(nums1, mid) + count_nums(nums2, mid);
                if(cnt >= k2){
                    ans2 = min(ans2, mid);
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            } 
            
            cout<<"A1: "<<ans1<<"A2: "<<ans2<<endl;
            ans = (ans1 + ans2) / 2;
            cout<<"A: "<<ans<<endl;
        }
        else{
            //Odd
            //Find kth element
            int k = (n+m) / 2;
            while(low <= high){
                double mid = (low+high) >> 1;
                double cnt = count_nums(nums1, mid) + count_nums(nums2, mid);
                if(cnt > k){
                    ans = min(ans, mid);
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }            
        }
        return ans;    
    }
};
