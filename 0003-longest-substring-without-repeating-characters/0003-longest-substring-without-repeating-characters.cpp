class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int n = s.size();
        int i=0, j=0;
        unordered_map<char, int> mp;

        while(j<n){
            char ch = s[j];
            if(mp.find(ch) != mp.end()){//exists
                i = max(i, mp[ch]+1);
            }
            mp[ch] = j;
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};