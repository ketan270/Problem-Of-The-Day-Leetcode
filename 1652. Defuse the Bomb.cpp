class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            for (int i = 0; i < n; i++) code[i] = 0;
            return ans;
        }

        else if (k > 0) {
            int sum = 0;

            for (int i = 0; i <= k; i++) {
                sum += code[i];
            }

            for (int i = 0; i < n; i++) {
                ans[i] = sum - code[i];
                sum -= code[i];
                sum += code[(i + k + 1) % n];
            }
        }

        else {
            k = abs(k);
            int sum = 0;

            for (int i = 0; i <= k; i++) {
                sum += code[(n - i) % n];
            }

            for (int i = 0; i < n; i++) {
                ans[i] = sum - code[i];
                sum -= code[(n - k + i) % n];
                sum += code[(i + 1) % n];
            }
        }
        return ans;
    }
};
