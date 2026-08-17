class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==0) return true;
        int lst = 0;
        for(int i=0; i<n-1; i++){
            if(lst < i) return false;
            lst = max(lst, nums[i]+i);
            if(lst >= n-1) return true;
        }
        return false;
    }
};