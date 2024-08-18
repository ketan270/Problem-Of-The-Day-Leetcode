class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n+1);
        res[1] = 1; // first ugly number
        int res2 = 1, res3 = 1, res5 = 1;
        for (int i = 2; i <= n; i++) {
            int t2 = res[res2] * 2;
            int t3 = res[res3] * 3;
            int t5 = res[res5] * 5;
            res[i] = min({t2, t3, t5}); // next ugly number is the smallest
                                        // possible one that hasn't been added
                                        // to the sequence yet
            if (res[i] == t2) res2++;
            if (res[i] == t3) res3++;
            if (res[i] == t5) res5++;
        }
        return res[n];
    }
};
