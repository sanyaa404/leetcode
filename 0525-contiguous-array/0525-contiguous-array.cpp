class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        freq[0] = -1;
        int maxi = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) sum--;
            else sum++;

            if(freq.count(sum)){
                maxi = max(maxi, i-freq[sum]);
            }else{
                freq[sum] = i;
            }
        }

        return maxi;
    }
};