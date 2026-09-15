class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mini;
        deque<int> maxi;
        int n = nums.size();
        int l=0;
        int ans = 0;

        for(int r=0; r<n; r++){
            while(!mini.empty() && mini.back() > nums[r]){
                mini.pop_back();
            }
            mini.push_back(nums[r]);

            while(!maxi.empty() && maxi.back() < nums[r]){
                maxi.pop_back();
            }
            maxi.push_back(nums[r]);

            while(maxi.front() - mini.front() > limit){
                if(nums[l] == maxi.front()) maxi.pop_front();
                if(nums[l] == mini.front()) mini.pop_front();
                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};