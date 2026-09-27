class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int maxRow = -1;
            int maxi = -1;
            for(int i=0; i<n; i++){
                if(mat[i][mid] > maxi){
                    maxRow = i;
                    maxi = mat[i][mid];
                }
            }
            bool greater = true;

            if(mid-1>=0 && mat[maxRow][mid-1] > maxi){
                greater = false;
                high = mid-1;
            }
            if(mid+1<m && mat[maxRow][mid+1] > maxi){
                greater = false;
                low = mid+1;
            }

            if(greater) return {maxRow, mid};
        }
        return {0,0};
    }
};