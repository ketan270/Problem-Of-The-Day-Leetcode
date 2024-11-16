class Solution {
public:
    vector<int> resultsArray(const vector<int>& a, const int &k) {
        vector<int> r(a.size() - k + 1);
        for (int i = 0, cons = 1; i < a.size(); i++) {
            cons = (i && a[i] == a[i - 1] + 1) ? cons + 1 : 1;
            if (i + 1 >= k) r[i - k + 1] = (cons >= k ? a[i] : -1);
        }
        return r;
    }
};
