class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            while(nums[i] > 0 && nums[i] < nums.size() && i!=nums[i] && nums[i] != nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }
        }

        for(int i=1; i<n; i++){
            if(nums[i] != i) return i;
        }

        if(nums[0] == n) return n+1;
        return n;
    }
};