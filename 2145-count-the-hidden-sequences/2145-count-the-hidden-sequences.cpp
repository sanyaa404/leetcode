class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long pref = 0;
        long mini = 0;
        long maxi = 0;
        for(int d: diff){
            pref += d;
            mini = min(mini, pref);
            maxi = max(maxi, pref);
        }
        return max(0, (int)((upper-maxi)-(lower-mini)+1));
    }
};