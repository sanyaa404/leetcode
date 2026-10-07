class Solution {
public:
    bool isPoss(long long k, vector<int>& chargeTimes, vector<int>& runningCosts, long long budget){
        int n = chargeTimes.size();
        deque<long long> dq; 
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            while (!dq.empty() &&
                   chargeTimes[dq.back()] <= chargeTimes[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            sum += runningCosts[j];
            if (j >= k - 1) {
                long long maxCharge = chargeTimes[dq.front()];
                long long totalCost =
                    maxCharge + 1LL * k * sum;
                if (totalCost <= budget)
                    return true;
                if (dq.front() == j - k + 1)
                    dq.pop_front();
                sum -= runningCosts[j - k + 1];
            }
        }
        return false;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget){
        int n = chargeTimes.size();
        long long low = 1, high = n;
        long long ans = 0;

        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isPoss(mid, chargeTimes, runningCosts, budget)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return (int)ans;
    }
};