class Solution {
public:
    //sum(i...j) = pref(j) - pref(i-1)
    //k = pref(j) - pref(i-1)
    //pref(i-1) = pref(j)-k
    // so if pref(j)-k i.e. pref(i-1) has been seen n times before, i can have n subarrays with sum = k
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int pref = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            pref += nums[i];
            if(freq.count(pref-k)){
                ans += freq[pref-k]; 
            }
            freq[pref]++;
        }
        return ans;
    }
};