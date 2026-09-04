class Solution {
public:
    double dfs(string s1, string s2, unordered_set<string> &vis, unordered_map<string, vector<pair<string, double>>>& adj, double prod){
        if(s1 == s2) return prod;
        vis.insert(s1);
        for(auto it: adj[s1]){
            if(!vis.count(it.first)){
                double res = dfs(it.first, s2, vis, adj, prod * it.second);
                if(res != -1.0) return res;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = values.size();

        for(int i=0; i<n; i++){
            auto &v = equations[i];
            double val = values[i];

            adj[v[0]].push_back({v[1], val});
            adj[v[1]].push_back({v[0], 1.0/val});
        }
        vector<double> ans;
        for(auto q: queries){
            if(!adj.count(q[0]) || !adj.count(q[1])){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> vis;
            ans.push_back(dfs(q[0],q[1],vis,adj,1.0));
        }
        return ans;
    }
};

//a->b = 2
//b->c = 3
//a->b->c ((a/b)*(b/c)) -> a/c -> 2*3 = 6
//b->a = 1/a->b