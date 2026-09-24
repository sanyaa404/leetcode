#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using oset = tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        oset st;
        long long cost = 0;

        for(int i=0; i<n; i++){
            int cnt1 = st.order_of_key({instructions[i], INT_MIN});
            int cnt2 = st.size() - st.order_of_key({instructions[i], INT_MAX});
            cost += min(cnt1, cnt2);
            st.insert({instructions[i], i});
        }

        return cost % 1000000007;
    }
};