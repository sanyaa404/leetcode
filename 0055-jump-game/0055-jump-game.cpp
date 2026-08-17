//dp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        int lastTrueIdx = n-1;
        for (int i = n-1; i >= 0; i--) {
            if (i + nums[i] >= n - 1) {
                dp[i] = true;
                lastTrueIdx = i;
            }
        
            if (i + nums[i] >= lastTrueIdx) {
                dp[i] = true;
                lastTrueIdx = i;
            }
        }

        return dp[0];
    }
};

//greedy
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1 || n==0) return true;
//         int lst = 0;
//         for(int i=0; i<n-1; i++){
//             if(lst < i) return false;
//             lst = max(lst, nums[i]+i);
//             if(lst >= n-1) return true;
//         }
//         return false;
//     }
// };