class Solution {
public:
    bool canChange(string start, string target) {
        int L = 0;
        int M = 0;
        int n = start.length();
        int tarspace = 0;
        int staspace = 0;

        while (L < n && M < n) {
            while (L < n && target[L] == '_') {
                tarspace++;
                L++;
            }
            while (M < n && start[M] == '_') {
                M++;
                staspace++;
            }

            if (L < n && M < n) {
                if (target[L] != start[M]) {
                    return false;
                }
                if (target[L] == 'L') {
                    if (tarspace > staspace)
                        return false;
                } else if (staspace > tarspace) {
                    return false;
                }
                L++;
                M++;
            }
        }

        // Check remaining characters
        while (L < n) {
            if (target[L] != '_')
                return false;
            L++;
        }
        while (M < n) {
            if (start[M] != '_')
                return false;
            M++;
        }

        return true;
    }
};

void IO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
