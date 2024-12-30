class Solution {
public:
    int dp[100005];
    int MOD = 1e9 + 7;
    int func(int low, int high, int zero, int one, int size){
        // Base Condition
        if(size > high){
            return 0;
        }

        // check if the value is already present in the  cache
        if(dp[size] != -1){
            return dp[size];
        }

        // check if current size of the string is already more then low.
        // If so, then can consider this as our answer
        int temp = size >= low ? 1 : 0;
        long long zero_cnt = func(low, high, zero, one, size + zero);
        long long one_cnt = func(low, high, zero, one, size + one);

        return dp[size] = (zero_cnt + one_cnt + temp) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // Initialisation
        memset(dp, -1, sizeof(dp));

        return func(low, high, zero, one, 0);
    }
};
