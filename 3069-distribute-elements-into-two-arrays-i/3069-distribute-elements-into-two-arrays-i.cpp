class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int back1 = arr1[0], back2 = arr2[0];

        for(int i=2; i<n; i++){
            if(back1 > back2){
                arr1.push_back(nums[i]);
                back1=nums[i];
            }else{
                arr2.push_back(nums[i]);
                back2=nums[i];
            }
        }
        for(int i=0; i<arr2.size();i++) arr1.push_back(arr2[i]);
        return arr1;
    }
};