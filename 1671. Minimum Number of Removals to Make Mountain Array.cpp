class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        int min_ = n;
        vector<int> v(n), p(n, 0);
        v.resize(0);
        for (int i = 0; i < n; ++i) {
            int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            if (x == v.size()) {
                v.push_back(a[i]);
            } else {
                v[x] = a[i];
            }
            p[i] = x;
        }
        v.resize(0);        
        for (int i = n - 1; i > -1; --i) {
            int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            if (x == v.size()) {
                v.push_back(a[i]);
            } else {
                v[x] = a[i];
            }
            if (p[i] && x) {
                min_ = min(min_, n - p[i] - x - 1);
            }
        }
        return min_;
    }
};
