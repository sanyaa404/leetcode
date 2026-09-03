class SnapshotArray {
public:
    unordered_map<int, vector<pair<int, int>>> arr;
    int snapId;

    SnapshotArray(int length) {
        snapId = 0;
    }

    void set(int index, int val) {
        arr[index].push_back({snapId, val});
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        if (arr.find(index) == arr.end())
            return 0;
        vector<pair<int, int>>& v = arr[index];
        int l = 0;
        int r = v.size() - 1;
        int ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m].first <= snap_id) {
                ans = v[m].second;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;
    }
};