class Solution {
public:
int n, m;
    void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || vis[i][j]) return;
        vis[i][j] = 1;
        dfs(i+1, j, grid, vis);
        dfs(i-1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i, j-1, grid, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]!='0'){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};