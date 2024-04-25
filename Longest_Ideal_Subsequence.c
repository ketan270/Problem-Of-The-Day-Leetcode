int longestIdealString(char *s, int k) {
    int dp[27] = {0};
    int n = strlen(s);

    for (int i = n - 1; i >= 0; i--) {
        char cc = s[i];
        int idx = cc - 'a';
        int maxi = -__INT_MAX__;

        int left = (idx - k) > 0 ? (idx - k) : 0;
        int right = (idx + k) < 26 ? (idx + k) : 26;

        for (int j = left; j <= right; j++) {
            maxi = maxi > dp[j] ? maxi : dp[j];
        }

        dp[idx] = maxi + 1;
    }

    int max = -__INT_MAX__;
    for (int i = 0; i < 27; i++) {
        if (dp[i] > max)
            max = dp[i];
    }

    return max;
}
