class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r=n-1;
        int mini = nums[0];

        while(l<=r){
            int m = (l+r)/2;
            mini = min(mini, nums[m]);
            if(nums[l] <= nums[m]){
                //left to mid is the sorted part
                mini = min(mini, nums[l]);
                l = m+1;
            }else{
                //mid to right is sorted part
                r = m-1;
            }
        }

        return mini;
    }
};