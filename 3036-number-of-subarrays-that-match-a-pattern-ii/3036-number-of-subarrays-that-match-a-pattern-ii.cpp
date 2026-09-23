class Solution {
public:
    vector<int> buildLPS(vector<int>& pat){
        int n = pat.size();
        vector<int> lps(n,0);
        int p=0, s=1;
        while(s<n){
            if(pat[p] == pat[s]){
                lps[s] = p+1;
                p++;
                s++;
            }
            else{
                if(p == 0){
                    lps[s] = 0;
                    s++;
                }else{
                    p = lps[p-1];
                }
            }
        }
        return lps;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        if(n < m+1) return 0;

        int cnt=0;

        vector<int> match;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                match.push_back(1);
            }else if(nums[i] == nums[i-1]){
                match.push_back(0);
            }else{
                match.push_back(-1);
            }
        }

        vector<int> lps = buildLPS(pattern);

        int i=0;
        int j=0;

        while(i<match.size()){
            if(match[i] == pattern[j]){
                i++;
                j++;
                if(j==m){
                    cnt++;
                    j = lps[j-1];
                }
            }else{
                if(j!=0) j = lps[j-1];
                else i++;
            }
        }

        return cnt;
    }
};
