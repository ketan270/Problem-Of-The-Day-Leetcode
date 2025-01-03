class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0, prefixSum = 0;

        // Compute total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        int cnt = 0;

        // Dynamically compute prefix sum and check valid splits
        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            if (prefixSum >= (totalSum - prefixSum)) {
                cnt++;
            }
        }

        return cnt;
    }
};
