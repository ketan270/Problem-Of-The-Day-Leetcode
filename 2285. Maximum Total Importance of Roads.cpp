class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> count(n);
        for (vector<int>& road : roads) {
            count[road[0]]++;
            count[road[1]]++;
        }
        long long ans = 0;
        sort(count.begin(), count.end());
        int imp = n;
        for (int i = n - 1; i >= 0; i--) {
            ans += ((long long)count[i] * imp);
            imp--;
        }
        return ans;
    }
};
