class Solution {
public:
    int primo=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraysums;
        for (int start = 0; start < n; ++start) {
            int sum = 0;
            for (int end = start; end < n; ++end) {
                sum += nums[end];
                subarraysums.push_back(sum);
            }
        }
        sort(subarraysums.begin(), subarraysums.end());
        int result = 0;
        for (int i = left - 1; i < right; ++i) {
            result =(result+ subarraysums[i])%primo;
        }
        return result;
    }
};
