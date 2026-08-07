class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        //to the left of l, all elements are non-zero & in correct place
        //r finds the non-0 element and l is the position where the next non-zero element is placed
        while(r<n){
            if(nums[r] == 0){
                r++;
                continue;
            }
            swap(nums[l], nums[r]);
            l++; r++;
        }
    }
};