class Solution {
public:
    int convertBin(string s) {
        int ans = 0;
        int n = s.length();
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1')
                ans += pow(2, j);
            j++;
        }
        return ans;
    }
    
    int solve(int n) {
        string s;
        while (n > 0) {
            if (n & 1) {
                s.push_back('0');
            } else {
                s.push_back('1');
            }
            n = n >> 1;
        }
        reverse(s.begin(), s.end());
        int ans = convertBin(s);
        return ans;
    }
    
    int findComplement(int num) {
        return solve(num);
    }
};
