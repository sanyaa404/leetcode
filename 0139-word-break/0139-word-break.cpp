class Solution {
public:
    bool solve(int i, int n, string &s, unordered_set<string> &words, vector<int> &dp){
        if(i>=n){
            return true;
        }
        if(dp[i] != -1) return dp[i];
        string word = "";
        for(int k=i; k<=n; k++){
            word += s[k];
            //add partition
            if(words.find(word) != words.end()){
                if(solve(k+1, n, s, words, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0, n, s, words, dp);
    }
};