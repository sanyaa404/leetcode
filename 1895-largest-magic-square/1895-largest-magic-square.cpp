class Solution {
public:
    bool isValid(int i, int j, int k, vector<vector<int>> &grid){
        int target = 0;
        for (int y = j; y < j + k; y++) {
            target += grid[i][y];
        }

        for(int x=i; x<i+k; x++){
            int sum = 0;
            for(int y=j; y<j+k; y++){
                sum += grid[x][y];
            }
            if(sum != target) return false;
        }
        
        for(int y=j; y<j+k; y++){
            int sum = 0;
            for(int x=i; x<i+k; x++){
                sum += grid[x][y];
            }
            if(sum != target) return false;
        }
        int diag1=0, diag2=0;
        for(int x=i; x<i+k; x++){
            for(int y=j; y<j+k; y++){
                if((x-i) - (y-j) == 0){
                    diag1 += grid[x][y];
                }
                if((x-i) + (y-j) == k-1){
                    diag2 += grid[x][y];
                }
            }
        }

        return (diag1 == target && diag2 == target);
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int k=min(n,m); k>=2; k--){
            for(int i=0; i+k<=n; i++){
                for(int j=0; j+k<=m; j++){
                    if(isValid(i,j,k,grid)) return k;
                }
            }
        }
        return 1;
    }
};