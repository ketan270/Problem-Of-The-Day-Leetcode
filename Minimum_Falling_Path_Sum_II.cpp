class Solution {
public:
    int dp[201][201];
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return find(grid, 0, 0);
    }
    
    int find(vector<vector<int>>& grid, int i, int j) {
        if(i>=grid.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=0; k<grid.size(); k++) {
            if(k==j && !(i==0 && j == 0)) {
                continue;
            }
            mn = min(mn, grid[i][k]+find(grid,i+1, k));
        }
        return dp[i][j]=mn;
    }
};
