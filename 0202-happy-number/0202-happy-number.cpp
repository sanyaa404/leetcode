class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        string num = to_string(n);
        while(true){
            int l = num.size();
            int sum = 0;
            for(int i=0; i<l; i++){
                sum += pow(num[i]-'0', 2);
            }
            if(sum == 1) return true;
            if(st.count(sum)) return false;
            st.insert(sum);
            num = to_string(sum);
        }
        return false;
    }
};