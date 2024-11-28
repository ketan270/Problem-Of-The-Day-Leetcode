class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<int>>ms;
        vector<vector<int>>d(n, vector<int>(m, -1));
        vector<int> di = {0, 0, 1, -1};
        vector<int> dj = {-1, 1, 0, 0};
        d[0][0] = grid[0][0];
        ms.insert({d[0][0], 0, 0});
        while (!ms.empty()) {
            auto top = *ms.begin();
            ms.erase(ms.begin());
            if (d[top[1]][top[2]] != -1 && d[top[1]][top[2]] < top[0])
                continue;
            for (int k = 0; k < 4; k++) {
                int ii = top[1] + di[k];
                int jj = top[2] + dj[k];
                if (!(ii >= 0 && ii < n && jj >= 0 && jj < m))
                    continue;
                if (d[ii][jj] == -1) {
                    d[ii][jj] = d[top[1]][top[2]] + grid[ii][jj];
                    ms.insert({d[ii][jj], ii, jj});
                    continue;
                }
                if (d[ii][jj] > d[top[1]][top[2]] + grid[ii][jj]) {
                    d[ii][jj] = d[top[1]][top[2]] + grid[ii][jj];
                    ms.insert({d[ii][jj], ii, jj});
                }
            }
        }
        return d[n-1][m-1];
    }
};
