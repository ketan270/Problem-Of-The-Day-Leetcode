class Solution {
private:
    // Function that returns max number of stones that current player
    // can get if game starts with the current player from pile at 
    // index idx and the current m, if both players play optimally
    int playOptimally(int idx, int m, vector<int>& piles, vector<int>& suffixSum, vector<vector<int>>& memo) {
        int n = piles.size();

        if (idx >= n) {  // check for edge cases
            return 0;
        }

        // If sub-problem is already solved, no need to solve it again
        if(memo[idx][m] != -1) return memo[idx][m];

        //variable to store sum of stones in the first X piles
        int sum = 0; 
        //variable to store the maximum stones the current player can get
        int ans = INT_MIN;

        for (int i = idx; i<idx + 2*m && i < n; i++) {
            sum += piles[i];
            int X = i - idx + 1; // number of piles choosen
            int tempM = max(m,X);  // update m for next player
            // below variable stores max stones the other player can
            // get from the remaining piles (if both play optimally)
            int next = playOptimally(i+1, tempM, piles, suffixSum,memo);      
            // remaining piles store suffixSum[i+1] number of stones
            // in total, so subtract next from it to get number of 
            // stones the current player can get from the remaining
            // piles. Add sum to it, since those stones are also picked
            // by the current player
            ans = max(ans, suffixSum[i+1] - next + sum);
        }

        return memo[idx][m] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        if (n == 1) return piles[0];  // edge case

        vector<int> suffixSum(n+1,0);

        // calculate suffixSums
        for (int i = n-1; i>=0; i--) {
            suffixSum[i] = suffixSum[i+1] + piles[i];
        }

        // Initialize memo table
        vector<vector<int>> memo(n, vector<int>(n, -1));

        return playOptimally(0, 1, piles, suffixSum, memo);
    }
};
