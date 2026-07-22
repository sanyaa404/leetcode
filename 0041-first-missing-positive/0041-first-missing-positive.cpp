class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi = nums.size()+1;
        vector<bool> exists(maxi+1);
        for(int num: nums){
            if(num>0 && num <= maxi+1) exists[num] = true;
        }
        for(int i=1; i<=maxi; i++){
            if(!exists[i]) return i;
        }
        return maxi;
    }
};