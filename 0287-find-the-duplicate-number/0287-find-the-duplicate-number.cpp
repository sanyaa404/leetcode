class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int idx = nums[0];
        while(true){
            int newidx = nums[idx];
            if(nums[idx] == idx) return idx;
            nums[idx] = idx;
            idx = newidx;
        }
        return 0;
    }
};