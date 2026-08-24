class TimeMap {
public:
    unordered_map<string, vector<int>> mp;
    unordered_map<string, string> timemap;
    TimeMap() {
        
    }

    int search(vector<int> &v, int t){
        int s=0;
        int e=v.size()-1;
        int ans = -1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(v[m] == t) return t;
            if(v[m] > t){
                e = m-1;
            }else{
                ans = v[m];
                s = m+1;
            }
        }
        return ans;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(timestamp);
        string tkey = key + "%" + to_string(timestamp);
        timemap[tkey] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        vector<int> &v = mp[key];
        int t = search(v, timestamp);
        if(t==-1) return "";
        string tkey = key + "%" + to_string(t);
        return timemap[tkey];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */