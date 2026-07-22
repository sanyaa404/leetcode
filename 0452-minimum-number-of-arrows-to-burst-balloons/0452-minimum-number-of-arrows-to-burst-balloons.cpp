class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int i = 1;
        int cnt = 0;
        int start = points[0][0];
        int end = points[0][1];
        while(i < n){
            if(points[i][0]>=start && points[i][0]<=end){
                end = min(end, points[i][1]);
                i++;
            }else{
                cnt++;
                start = points[i][0];
                end = points[i][1];
                i++;
            }
        }
        cnt++;
        return cnt;
    }
};