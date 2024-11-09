class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> bits = getBits(x);
        int cnt = 0;
        for (int i = 0; i < bits.size(); i++) {
            cnt += (bits[i] == 0);
        }
        if ((1 << cnt) >= n) {
            build(bits, n - 1, cnt);
            return buildResult(bits);
        }
        while ((1 << cnt) < n) {
            bits.push_back(0);
            cnt++;
        }
        build(bits, n - 1, cnt);
        return buildResult(bits);
    }
    vector<int> getBits(int n) {
        vector<int> bits;
        while (n > 0) {
            bits.push_back(n & 1);
            n = (n >> 1);
        }
        return bits;
    }

    void build(vector<int>& bits, int n, int cnt) {
        int sz = bits.size(); 
        cnt--;
        for (int i = sz - 1; i >= 0; i--) {
            if (bits[i] == 0) {
                if ((1 << cnt) <= n) {
                    bits[i] = 1;
                    n -= (1 << cnt);
                }
                cnt--;
            }
        }     
    }
    long long buildResult(vector<int>& bits) {
        long long result = 0;
        for (int i = 0; i < bits.size(); i++) {
            if (bits[i])
                result += (long long)(1LL << i);
        }
        return result;
    }
};
