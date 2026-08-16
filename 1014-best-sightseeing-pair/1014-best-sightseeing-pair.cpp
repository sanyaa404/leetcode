class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxPrev = values[0];
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans, maxPrev+values[i]-i);
            maxPrev = max(maxPrev, values[i]+i);
        }
        return ans;
    }
};