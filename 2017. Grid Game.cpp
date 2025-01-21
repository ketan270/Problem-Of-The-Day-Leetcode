class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long row1 = accumulate(grid[0].begin(), grid[0].end(), 0ll), row2 = 0, min_ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            row1 -= grid[0][i];
            min_ans = min(min_ans, max(row1, row2));
            row2 += grid[1][i];
        }
        return min_ans;
    }
};
