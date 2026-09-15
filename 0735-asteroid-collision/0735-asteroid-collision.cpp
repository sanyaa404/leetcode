class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        vector<int> ans;
        int n = a.size();

        for(int i=n-1; i>=0; i--){
            int curr = a[i];
            if(s.empty() || curr < 0) s.push(a[i]);
            else{
                while(!s.empty() && s.top()<0 && curr>0){
                    int top = abs(s.top());
                    if(curr > top){
                        s.pop();
                    }else if(curr < top){
                        curr = 0;
                    }else{
                        curr = 0;
                        s.pop();
                    }
                }
                if(curr != 0) s.push(curr);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};