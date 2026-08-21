class Solution {
public:
    unordered_map<char, vector<char>> adj;
    unordered_map<char, int> indeg;
    bool comp(string s1, string s2){
        int n = min(s1.size(), s2.size());
        int i = 0;

        while(i<n && s1[i] == s2[i]){
            i++;
        }

        if(i == n) return s1.size() <= s2.size();

        if(find(adj[s1[i]].begin(), adj[s1[i]].end(), s2[i]) == adj[s1[i]].end()){
            adj[s1[i]].push_back(s2[i]);
            indeg[s2[i]]++;
        }

        return true;
    }
    string alienOrder(vector<string>& words) {
        int n = words.size();
        for (string word : words) {
            for (char c : word) {
                indeg[c] = 0;
            }
        }

        for(int i=0; i<n-1; i++){
            string wr1 = words[i];
            string wr2 = words[i+1];
            // cout << wr1 << " " << wr2 << endl;
            if(!comp(wr1, wr2)) return "";
        }

        queue<char> q;
        for(auto it: indeg){
            if(it.second == 0) {
                q.push(it.first);
                // cout << it.first << endl;
            }
        }

        string ans = "";
        while(!q.empty()){
            char ch = q.front();
            q.pop();
            ans += ch;

            for(int nbg: adj[ch]){
                indeg[nbg]--;
                if(indeg[nbg] == 0) q.push(nbg);
            }
        }

        //cycle
        if (ans.size() != indeg.size()) {
            return "";
        }

        return ans;
    }
};