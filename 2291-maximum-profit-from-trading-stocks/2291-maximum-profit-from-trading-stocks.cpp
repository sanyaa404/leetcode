class Solution {
public:
    int solve(int idx, int b, int n, vector<int>& present, vector<int>& future, vector<vector<int>>& dp){
        if(idx >= n or b < 0) return 0;
        if(dp[idx][b] != -1) return dp[idx][b];

        //not take
        int notTake = solve(idx+1, b, n, present, future, dp);

        //take
        int take = 0;
        if(b >= present[idx]){
            take = future[idx] - present[idx] + solve(idx+1, b-present[idx], n, present, future, dp);
        }
        return dp[idx][b] = max(take, notTake);
    }
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        vector<vector<int>> dp(n, vector<int>(budget+1, -1));
        return solve(0, budget, n, present, future, dp);
    }
};