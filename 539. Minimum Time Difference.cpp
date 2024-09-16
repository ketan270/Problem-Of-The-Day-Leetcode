class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int, int>> v;
        int n = timePoints.size();
        for (int i = 0; i < n; i++)
            v.push_back(
                {(timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0'),
                 (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0')});
        sort(v.begin(), v.end());
        int result = INT_MAX;
        for (int i = 0; i < 2 * v.size() - 1; i++) {
            if (i >= v.size() - 1)
                v[(i + 1) % n].first += 24;
            result =
                min(result,
                    abs((v[i % n].first * 60 + v[i % n].second) -
                        (v[(i + 1) % n].first * 60 + v[(i + 1) % n].second)));
        }
        return result;
    }
};
