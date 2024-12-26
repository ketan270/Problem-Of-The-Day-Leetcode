class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums) total += num;

        if ((target + total) % 2 != 0 || abs(target) > total) return 0;

        int sumRequired = (target + total) / 2;

        vector<int> dp(sumRequired + 1, 0);

        dp[0] = 1; 

        for (int num : nums) {
            for (int sum = sumRequired; sum >= num; --sum) {
                dp[sum] += dp[sum - num];
            }
        }

        return dp[sumRequired];
    }
};
