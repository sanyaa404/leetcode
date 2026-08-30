class Solution {
public:
    bool check(int row, int col, int n, vector<string>& path){
        for(int i=0 ;i<row; i++){
            if(path[i][col] == 'Q') return false;
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(path[i][j] == 'Q') return false;
        }

        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(path[i][j] == 'Q') return false;
        }

        return true;
    }
    void solve(int row, int n, vector<vector<string>> &ans, vector<string> &path){
        if(row == n){
            ans.push_back(path);
            return;
        }

        for(int col=0; col<n; col++){
            path[row][col] = 'Q';
            if(check(row, col, n, path)){
                solve(row+1, n, ans, path);
            }
            path[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> path(n, s);
        solve(0, n, ans, path);
        return ans;
    }
};