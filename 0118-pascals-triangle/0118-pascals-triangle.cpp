class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> last = {1};
        ans.push_back(last);

        for(int i=0; i<numRows-1; i++){
            int n = last.size();
            vector<int> dp;
            dp.push_back(1);
            for(int j=0; j<n-1; j++){
                dp.push_back(last[j] + last[j+1]);
            }
            dp.push_back(1);
            ans.push_back(dp);
            last = dp;
        }
        return ans;
    }
};