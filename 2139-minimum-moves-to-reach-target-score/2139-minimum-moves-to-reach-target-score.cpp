class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        int curr = 1;
        while(maxDoubles>0){
            int point = target/pow(2,maxDoubles);
            if(point == 0){
                maxDoubles--;
                continue;
            }
            while(point!=0 && curr != point){
                ans++;
                curr++;
            }
            ans++;
            curr *= 2;
            maxDoubles--;
        }
        return ans+target-curr;
    }
};