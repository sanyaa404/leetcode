#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    typedef tree<pair<int,int>, null_type, greater<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> oset;
    vector<int> resultArray(vector<int>& nums) {
        oset o1;
        oset o2;

        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        o1.insert({nums[0], 0});
        o2.insert({nums[1], 1});

        for(int i=2; i<n; i++){
            int cnt1 = o1.order_of_key({nums[i],INT_MAX});
            int cnt2 = o2.order_of_key({nums[i],INT_MAX}); //because we want strictly greater, so if value is same
            if(cnt1 > cnt2){
                arr1.push_back(nums[i]);
                o1.insert({nums[i],i});
            }else if(cnt1 < cnt2){
                arr2.push_back(nums[i]);
                o2.insert({nums[i],i});
            }else{
                if(arr1.size() <= arr2.size()){
                    arr1.push_back(nums[i]);
                    o1.insert({nums[i],i});
                }else{
                    arr2.push_back(nums[i]);
                    o2.insert({nums[i],i});
                }
            }
        }

        for(int i=0; i<arr2.size(); i++){
            arr1.push_back(arr2[i]);
        }

        return arr1;
    }
};