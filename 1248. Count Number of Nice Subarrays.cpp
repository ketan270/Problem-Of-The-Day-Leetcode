class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, oddCount = 0, prevCount = 0;
        int low = 0, high = 0;
        while (high < nums.size()) {
            if (nums[high] % 2 != 0) {
                oddCount++;
                prevCount = 0;
            }
            while (oddCount == k) {
                prevCount++;
                if (low < nums.size() && nums[low] % 2 == 1) {
                    oddCount--;
                }
                low++;
            }
            ans += prevCount;
            high++;
        }
        return ans;
    }
};
