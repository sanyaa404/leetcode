class Solution {
public:
    int solve(int i, int have, vector<int>& prices, int fee, vector<vector<int>> &dp){
        if(i >= prices.size()) return 0;

        if(dp[i][have] != -1) return dp[i][have];

        int ch1 = 0;
        int ch2 = 0;
        if(have){
            int sellNow = solve(i+1, !have, prices, fee, dp)-fee+prices[i];
            int sellLater = solve(i+1, have, prices, fee, dp);
            ch1 = max(sellNow, sellLater);
        }
        else{ //not have
            int buyNow = solve(i+1, !have, prices, fee, dp) - prices[i];
            int buyLater = solve(i+1, have, prices, fee, dp);
            ch2 = max(buyNow, buyLater);
        }
        return dp[i][have] = max(ch1, ch2);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0, 0, prices, fee, dp);
    }
};