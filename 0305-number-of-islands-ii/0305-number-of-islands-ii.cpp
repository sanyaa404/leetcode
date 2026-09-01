class Solution {
public:
    vector<int> parent;
    vector<int> sz;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;
        if (sz[px] < sz[py])
            swap(px, py);

        parent[py] = px;
        sz[px] += sz[py];

        return true;
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions){
        int total = m * n;

        //-1 means water
        parent.assign(total, -1);
        sz.assign(total, 1);

        vector<int> ans;
        int islands = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (auto& pos : positions) {
            int r = pos[0];
            int c = pos[1];

            int id = r * n + c;

            if (parent[id] != -1) {
                ans.push_back(islands);
                continue;
            }

            parent[id] = id;
            islands++;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int neighbor = nr * n + nc;
                if (parent[neighbor] == -1)continue;
                if (unite(id, neighbor)) {
                    islands--;
                }
            }
            ans.push_back(islands);
        }

        return ans;
    }
};