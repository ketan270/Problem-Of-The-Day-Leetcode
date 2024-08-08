class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> coords;
        vector<pair<int, int>> directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int counter = 1;
        cStart++;
        while (coords.size() < cols * rows) {
            cStart--;rStart++;
            for (auto [i, j] : directions) {
                for (int k = 0; k < counter; k++) {
                    rStart += i; cStart += j;
                    if (rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols) {
                        coords.push_back({rStart, cStart});
                    }
                }
            }
            counter += 2;
        }
        return coords;
    }
};
