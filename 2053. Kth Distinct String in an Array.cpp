class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for (const string& s : arr) {
            count[s]++;
        }
        for (const string& s : arr) {
            if (count[s] == 1) {
                k--;
                if (k == 0) {
                    return s;
                }
            }
        }
        return "";
    }
};
