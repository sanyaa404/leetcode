class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            while(nums[i] > 0 && nums[i] < nums.size() && i!=nums[i] && nums[i] != nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }
            i++;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != i) return i;
        }
        return nums[0] == nums.size() ? nums.size()+1 : nums.size();
    }
};