class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> minheap;

        int maxval = INT_MIN;
        for (int i = 0; i < k; i++) {
            minheap.push({nums[i][0], {i, 0}});
            maxval = max(maxval, nums[i][0]);
        }

        int rangestart = 0, rangeend = INT_MAX;

        while (!minheap.empty()) {
            auto [minvalue, pos] = minheap.top();
            minheap.pop();
            int row = pos.first, col = pos.second;

            if (maxval - minvalue < rangeend - rangestart) {
                rangestart = minvalue;
                rangeend = maxval;
            }

            if (col + 1 < nums[row].size()) {
                minheap.push({nums[row][col + 1], {row, col + 1}});
                maxval = max(maxval, nums[row][col + 1]);
            } else {
                break;
            }
        }
        return {rangestart, rangeend};
    }
};