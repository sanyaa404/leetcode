class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int pref = 1, suff = 1;

        for(int i=0; i<n-1; i++){
            pref *= nums[i];
            ans[i+1] *= pref;
        }

        for(int i=n-1; i>0; i--){
            suff *= nums[i];
            ans[i-1] *= suff;
        }

        return ans;
    }
};