class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 1;
        int h = n-2;
        while(l<=h){
            int m = (l+h)/2;
            if(arr[m] > arr[m-1] && arr[m] > arr[m+1]) return m;
            else if(arr[m] < arr[m+1]){
                l = m+1;
            }else{
                h = m-1;
            }
        }
        return -1;
    }
};