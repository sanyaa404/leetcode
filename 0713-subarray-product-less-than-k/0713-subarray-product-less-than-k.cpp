class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int l = 0;
        int prod = 1;

        for(int r=0; r<n; r++){
            prod *= nums[r];
            while(l<=r && prod >= k){
                prod /= nums[l];
                l++;
            }
            ans += (r-l+1);
        }
        return ans;
    }
};