class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> mp;

        for (int i = 0; i < keyName.size(); i++) {
            int h = stoi(keyTime[i].substr(0, 2));
            int m = stoi(keyTime[i].substr(3, 2));

            mp[keyName[i]].push_back(h * 60 + m);
        }

        vector<string> ans;

        for (auto &[name, times] : mp) {
            sort(times.begin(), times.end());

            for (int i = 2; i < times.size(); i++) {
                if (times[i] - times[i - 2] <= 60) {
                    ans.push_back(name);
                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};