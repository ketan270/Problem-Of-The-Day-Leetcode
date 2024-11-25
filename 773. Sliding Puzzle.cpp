class Solution {
    bool equal(vector<vector<int>>& board, vector<vector<int>>& reqConfig) {
        return board == reqConfig;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {

        int level = 0;

        vector<vector<int>> reqConfig = {{1, 2, 3}, {4, 5, 0}};

        if (equal(board, reqConfig)) {
            return level;
        }

        map<vector<vector<int>>, int> mp;

        mp[board] = 1;

        int n = 2, m = 3;

        queue<pair<vector<vector<int>>, pair<int, int>>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    q.push({board, {i, j}});
                    break;
                }
            }
        }

        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {

            int size = q.size();

            level++;

            while (size--) {

                auto newBoard = q.front().first;
                auto coordinates = q.front().second;

                q.pop();

                int x = coordinates.first;
                int y = coordinates.second;

                for (auto d : dir) {

                    int newX = x + d[0];
                    int newY = y + d[1];

                    if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                        vector<vector<int>> swappedBoard = newBoard;

                        swap(swappedBoard[x][y], swappedBoard[newX][newY]);

                        if (mp.count(swappedBoard)) {
                            continue;
                        }

                        mp[swappedBoard] = 1;

                        if (equal(swappedBoard, reqConfig)) {

                            return level;
                        }

                        q.push({swappedBoard, {newX, newY}});
                    }
                }
            }
        }

        return -1;
    }
};
