class Solution {
public:
    int N, M;
    long long solve(int r, int c, vector<vector<int>> &points, vector<vector<long long>> &dp){
        if(r == N) return 0;
        if(r == N - 1)return points[r][c];

        long long &ret = dp[r][c];
        if(~ret)return ret;

        ret = 0;
        for(int j = 0; j < M; j++){
            ret = max(ret, solve(r+1, j, points, dp) + points[r][c] - abs(c - j));
        }
        return ret;
    }
    long long maxPoints(vector<vector<int>>& points) {
        N = points.size(), M = points[0].size();
        long long mx = 0;
        vector<vector<long long>> dp(N, vector<long long>(M, -1));
        for(int i = 0; i < M; i++){
            mx = max(mx, solve(0, i, points, dp));
        }
        return mx;
    }
};
