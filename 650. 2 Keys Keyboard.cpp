class Solution {
public:

    int solve(int n, int prevcopied, int onscreen, vector<vector<int>> & dp){

        if(n == onscreen){
            return 0;
        }

        if(onscreen > n){
            return 1e8;
        }

        if(dp[prevcopied][onscreen] != -1){
            return dp[prevcopied][onscreen];
        }

        int paste = INT_MAX;
        if(prevcopied+onscreen <= n){
            paste = 1 + solve(n, prevcopied, prevcopied+onscreen, dp);
        }

        int copy = 2 + solve(n, prevcopied+onscreen, prevcopied+onscreen, dp);
        return dp[prevcopied][onscreen] = min(paste, copy);
    }

    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        // Uncomment for memoization approach
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve(n, 1, 0, dp);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[1][1] = 0;  
        
        for (int onscreen = 1; onscreen <= n; onscreen++) {
            for (int prevcopied = 0; prevcopied <= onscreen; prevcopied++) {
                if (dp[prevcopied][onscreen] == INT_MAX) continue;

                if (onscreen + prevcopied <= n && prevcopied > 0) {
                    dp[prevcopied][onscreen + prevcopied] = min(dp[prevcopied][onscreen + prevcopied], dp[prevcopied][onscreen] + 1);
                }

                if (onscreen + onscreen <= n) {
                    dp[onscreen][onscreen + onscreen] = min(dp[onscreen][onscreen + onscreen], dp[prevcopied][onscreen] + 2);
                }
            }
        }

        int result = INT_MAX;
        for (int i = 0; i <= n; i++) {
            result = min(result, dp[i][n]);
        }

        return result+1;
    }
};
