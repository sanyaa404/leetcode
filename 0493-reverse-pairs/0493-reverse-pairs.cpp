class Solution {
public:
    long long merge(vector<int>& arr, int l, int mid, int r) {
        long long cnt = 0;
        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
        vector<int> temp;
        int i = l;
        j = mid + 1;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }
        while (j <= r) {
            temp.push_back(arr[j++]);
        }
        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }
        return cnt;
    }

    long long mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;

        long long cnt = 0;
        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid + 1, r);
        cnt += merge(arr, l, mid, r);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return (int)mergeSort(nums, 0, nums.size() - 1);
    }
};