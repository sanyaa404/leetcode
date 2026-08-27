class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ele = nums[0];
        while(true){
            if(nums[ele] == ele) return ele;
            int temp = nums[ele];
            nums[ele] = ele;
            ele = temp;
        }
        return 0;
    }
};