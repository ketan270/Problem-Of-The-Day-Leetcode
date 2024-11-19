class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        long long sum = 0, result = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            sum += nums[i];
            if (i >= k) {
                mp[nums[i-k]]--;
                sum -= nums[i - k];
                if (mp[nums[i-k]] == 0) {
                    mp.erase(nums[i-k]);
                }
            }
            if (i < k - 1) continue;
            if (mp.size() == k) {
                result = max(result, sum);
            }
        }
        return result;
    }
};
