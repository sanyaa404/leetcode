class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;
        int maxi = 0;
        int l = 0;
        while(l < n - 1) {
            while(l < n - 1 && arr[l] >= arr[l + 1])
                l++;

            int r = l + 1;
            int cnt = 1;

            //inc
            while(r < n && arr[r] > arr[r - 1]) {
                cnt++;
                r++;
            }
            //no decreasing part
            if(r == n)
                break;

            //dec
            bool dec = false;
            while(r < n && arr[r] < arr[r - 1]) {
                cnt++;
                r++;
                dec=true;
            }

            if(dec)
                maxi = max(maxi, cnt);

            if(r < n && arr[r] == arr[r - 1])
                l = r;//skip
            else
                l = r - 1;
        }
        return maxi;
    }
};