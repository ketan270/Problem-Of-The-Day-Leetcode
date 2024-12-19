class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = 0, cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
            if (maxi == i) {
                cnt++;
            }
        }
        return cnt;
    }
};
