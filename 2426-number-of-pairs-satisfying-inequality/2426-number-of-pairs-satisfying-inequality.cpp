#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using oset = tree<pair<int,int>, null_type, less_equal<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();

        long long ans = 0;
        oset o;
        for(int i=0; i<n; i++){
            long long b = nums1[i]-nums2[i];
            ans += o.order_of_key({b+diff, INT_MAX});
            o.insert({b, i});
        }

        return ans;
    }
};