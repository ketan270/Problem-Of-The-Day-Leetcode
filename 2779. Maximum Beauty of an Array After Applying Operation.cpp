// Using sweep line 
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> nums1;

        // Step 1: Generate ranges for each number in nums
        for (int i = 0; i < nums.size(); i++) {
            nums1.push_back({nums[i] - k, nums[i] + k});
        }

        // Step 2: Use intervals to count i intervals
        vector<pair<int, int>> intervals;
        for (auto& range : nums1) {
            intervals.push_back({range.first, 1});  
            intervals.push_back({range.second + 1, -1}); 
        }

        // Step 3: Sort intervals by point, breaking ties by type
        sort(intervals.begin(), intervals.end());

        // Step 4: Sweep line to find maximum overlap
        int i = 0, mostCommon = 0, maxi = 0;
        for (auto& event : intervals) {
            i += event.second; 
            if (i > mostCommon) {
                mostCommon = i;
                maxi = event.first; 
            }
        }

        return mostCommon;
    }
};
