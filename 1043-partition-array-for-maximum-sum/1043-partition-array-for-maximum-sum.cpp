class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int>& dp){
        if(i >= arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int maxi = arr[i];
        int ans = 0;
        for(int j=i; j<i+k && j<arr.size(); j++){
            maxi = max(maxi, arr[j]);
            int cost = maxi*(j-i+1) + solve(j+1, arr, k, dp);
            ans = max(ans, cost);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};