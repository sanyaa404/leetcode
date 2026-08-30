class Solution {
public:
    bool solve(int i, int j, int n, string &s, unordered_set<string> &words, vector<vector<int>> &dp){
        if(i>j){
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        string word = "";
        int ans = 0;
        for(int k=i; k<=j; k++){
            word += s[k];
            //add partition
            if(words.find(word) != words.end()){
                ans = ans || solve(k+1,n-1, n, s, words, dp);
            }
        }
        return dp[i][j] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, n-1, n, s, words, dp);
    }
};