class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r=n-1;

        while(l<=r){
            int m = (l+r)/2;
            if(nums[m] == target) return true;
            while(nums[l] == nums[m] && nums[m] == nums[r]){
                l++;
                r--;
                if(l>r) break;
            }
            if(l>r) break;
            if(nums[l] <= nums[m]){
                //left to mid is the sorted part
                if(nums[l] <= target && nums[m] >= target){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }else{
                //mid to right is sorted part
                if(nums[m] <= target && nums[r] >= target){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
        }

        return false;
    }
};