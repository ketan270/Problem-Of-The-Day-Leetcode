class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        vector<long long> fac; // Flatten the factory
        for(auto &v:factory){
            fac.insert(fac.end(), v[1], v[0]);
        }
        sort(fac.begin(), fac.end());
        int r = robot.size();
        int f = fac.size();
        // dp[i][j] mean the minimum distance when we have i robot and j factory.
        // dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + dis(r[i], f[j])); 
        // => ith robot use jth factory or not use
        long long dp[100][10000];
        dp[0][0] = abs(fac[0]-robot[0]);
        for(int i=1; i<f; ++i){
            dp[0][i] = min(dp[0][i-1], abs(fac[i]-robot[0]));
        }
        for(int i=1; i<r; ++i){
            dp[i][i] = dp[i-1][i-1] + abs(fac[i]-robot[i]);
            for(int j=i+1; j<f; ++j){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(fac[j]-robot[i]));
            }
        }
        return dp[r-1][f-1];
    }
};
