class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for(auto it: intervals){
            starts.push_back(it[0]);
            ends.push_back(it[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int avail = 0;
        int rooms = 0;
        int e = 0;
        for(int st: starts){
            while(ends[e] <= st){
                avail++;
                e++;
            }
            avail ? avail-- : rooms++;
        }
        return rooms;
    }
};