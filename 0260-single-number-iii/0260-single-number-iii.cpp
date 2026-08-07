class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorRes = 0;
        for(int num : nums){
            xorRes ^= num;
        }

        //check what bit of the 2 soln numbers differs
        //if xor result if 110 -> then their 0th bit is same, but 1st, 2nd are different
        int diffBit;
        for(int i=0; i<31; i++){
            if((xorRes&(1<<i)) != 0){
                diffBit = i;
                break;
            } //ith bit is 1, found diff bit
        }

        //now we have the point where num1 & num2 are different
        //make 2 groups to find them
        int num1 = xorRes;
        int num2 = xorRes;
        for(int num : nums){
            if((num&(1<<diffBit)) == 0){
                num1 ^= num;
            }else {
                num2 ^= num;
            }
        }

        return {num1, num2};
    }
};