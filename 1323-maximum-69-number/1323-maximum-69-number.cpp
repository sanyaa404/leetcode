class Solution {
public:
    int maximum69Number (int num) {
        int ans = num;
        int firstSix = -1;
        int mul = 1;
        while(num > 0){
            int dig = num%10;
            num /= 10;
            if(dig == 6){
                firstSix = mul;
            } mul *= 10;
        }

        return (firstSix == -1) ? ans : ans + (3*firstSix);
    }
};