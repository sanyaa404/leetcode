//design for scaling
class HitCounter {
public:
    vector<pair<int, int>> v;
    HitCounter() {
        v.resize(300, {0,0});
    }
    
    void hit(int timestamp) {
        int t = timestamp%300;
        if(v[t].first == timestamp){
            v[t].second++;
        }else{
            v[t] = {timestamp, 1};
        }
    }
    
    int getHits(int timestamp) {
        int ans = 0;
        for(int i=0; i<300; i++){
            if(timestamp - v[i].first < 300) ans += v[i].second;
        }
        return ans;
    }
};

//normal soln
// class HitCounter {
// public:
//     queue<int> q;
//     HitCounter() {
        
//     }
    
//     void hit(int timestamp) {
//         q.push(timestamp);
//     }
    
//     int getHits(int timestamp) {
//         while(!q.empty() && timestamp - q.front() >= 300) q.pop();
//         return q.size();
//     }
// };

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */