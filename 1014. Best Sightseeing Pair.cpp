class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = values[0] + 0;
        int ans = INT_MIN;

        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, maxScore + values[i] - i);
            maxScore = max(maxScore, values[i] + i);
        }
        return ans;
    }
};
