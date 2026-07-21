class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = n;
        int i=0, j = 31;
        while(i < j){
            int left = (n >> i) & 1;
            int right = (n >> j) & 1;
            if(left != right) {    
                ans = ans^(1<<i);
                ans = ans^(1<<j);
            }
            i++; j--;
        }
        return ans;
    }
};