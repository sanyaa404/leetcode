class Solution {
public:
    bool check(queue<int> q, vector<int>& v){
        int i=0;
        while(!q.empty()){
            if(i>=v.size() || q.front() != v[i]) return false;
            q.pop();
            i++;
        }
        return true;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        if(n < m+1) return 0;

        int l = 0;
        queue<int> patCaptured;
        int cnt = 0;

        for(int r=1; r<n; r++){
            if(nums[r] > nums[r-1]){
                patCaptured.push(1);
            }else if(nums[r] == nums[r-1]){
                patCaptured.push(0);
            }else{
                patCaptured.push(-1);
            }

            if(r-l+1 == (m+1)){
                cnt += check(patCaptured, pattern);
                patCaptured.pop();
                l++;
            }
        }
        return cnt;
    }
};
