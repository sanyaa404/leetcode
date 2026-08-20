class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while(true){
            int sum = 0;
            while(n>0){
                sum += pow(n%10,2);
                n /= 10;
            }
            if(sum == 1) return true;
            if(st.count(sum)) return false;
            st.insert(sum);
            n = sum;
        }
        return false;
    }
};