class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        for(int k=i; k<=j; k++){
            int left = solve(i, k-1, nums, dp);
            int right = solve(k+1, j, nums, dp);
            int cost = left + right + (nums[i-1]*nums[k]*nums[j+1]); //because all elements in the range (i,j) have bursted-> so we go out of the range
            ans = max(ans, cost);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> nums2;
        nums2.push_back(1);
        for(int num: nums) nums2.push_back(num); //padding with 1s
        nums2.push_back(1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, nums2, dp);
    }
};