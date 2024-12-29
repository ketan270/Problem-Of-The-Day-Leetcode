class Solution {
    const int mod = 1e9 + 7;

    vector<vector<int>> dp;

    int helper(vector<string>& words, string& target, int w_idx, int t_idx, vector<vector<int>>& freq){
        if(t_idx == target.size()){
            return 1;
        }
        if(w_idx == words[0].size()){
            return 0;
        }

        if(dp[w_idx][t_idx] != -1){
            return dp[w_idx][t_idx];
        }

        long long cnt = 0;

        cnt = (cnt + (helper(words, target, w_idx + 1, t_idx, freq)%mod))%mod;

        long long f = freq[w_idx][target[t_idx] - 'a'];
        if(f > 0){
            cnt = (cnt + ((helper(words, target, w_idx+1, t_idx+1, freq)%mod) * (f%mod))%mod)%mod;
        }

        return dp[w_idx][t_idx] = cnt%mod;
    }

public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        vector<vector<int>> freq(n, vector<int>(26, 0));

        for(int i=0; i<words.size(); i++){
            for(int j=0; j<n; j++){
                freq[j][words[i][j] - 'a']++;
            }
        }

        return helper(words, target, 0, 0, freq);
    }
};
