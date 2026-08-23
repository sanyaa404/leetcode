class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        int n = nums.size();
        int i = 0;

        while(i<n){
            if(candidate == nums[i]) count++;
            else{
                if(count == 0) candidate = nums[i];
                else count--;
            }
            i++;
        }
        return candidate;
    }
};