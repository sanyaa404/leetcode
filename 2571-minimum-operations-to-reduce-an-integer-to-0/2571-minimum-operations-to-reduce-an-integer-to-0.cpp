class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n>0){
            if((n&3) == 3){
                //ends with 11
                n = n+1;
                ans++;
            }else if((n&1) == 1){
                //ends with 01
                n = n-1;
                ans++;
            }else{
                //ends with 0
                n = (n>>1);
            }
        }
        return ans;
    }
};