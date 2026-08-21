class Solution {
public:
    int maximum = 1;
    pair<int, bool> helper(int node, vector<vector<int>>& adj,
                           vector<int>& colors) {
        int size = 1;
        bool valid = true;
        for (int child : adj[node]) {
            auto [childSize, childValid] =
                helper(child, adj, colors);
            if (!childValid || colors[node] != colors[child]) {
                valid = false;
            }
            size += childSize;
        }
        // Only consider this subtree if it is completely valid.
        if (valid) {
            maximum = max(maximum, size);
        }
        return {size, valid};
    }

    int maximumSubtreeSize(vector<vector<int>>& edges,
                           vector<int>& colors) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        helper(0, adj, colors);
        return maximum;
    }
};