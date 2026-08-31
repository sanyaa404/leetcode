class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;

        int num = n;
        while(!st.count(num)){
            st.insert(num);
            int sum = 0;
            while(num){
                sum += pow(num%10, 2);
                num /= 10;
            }
            if(sum == 1) return true;
            num = sum;
        }
        return false;
    }
};