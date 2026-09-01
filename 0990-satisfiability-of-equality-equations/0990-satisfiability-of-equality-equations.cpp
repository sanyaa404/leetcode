class Solution {
public:
    vector<int> par;

    int find(int x) {
        if(par[x] == x)
            return x;

        return par[x] = find(par[x]);
    }

    void unite(char ch1, char ch2) {
        int a = ch1 - 'a';
        int b = ch2 - 'a';

        int upa = find(a);
        int upb = find(b);

        if(upa == upb) return;

        par[upa] = upb;
    }

    bool equationsPossible(vector<string>& equations) {
        par.resize(26);

        for(int i = 0; i < 26; i++)
            par[i] = i;

        for(string s : equations) {
            if(s[1] == '=') {
                unite(s[0], s[3]);
            }
        }

        for(string s : equations) {
            if(s[1] == '!') {
                if(find(s[0] - 'a') == find(s[3] - 'a'))
                    return false;
            }
        }

        return true;
    }
};