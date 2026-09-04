class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> idx;
        long long pref = 0;
        int maxi = 0;
        idx[0] = -1;

        for(int i=0; i<nums.size(); i++){
            pref += nums[i];
            if(idx.count(pref-k)) maxi = max(maxi, i-idx[pref-k]);
            if(!idx.count(pref)) idx[pref] = i;
        }
        return maxi;
    }
};