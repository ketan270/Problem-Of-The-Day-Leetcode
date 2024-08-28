class Solution {
public:
    int n, m;

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // Get the dimensions of the grids
        m = grid1.size();
        n = grid1[0].size();

        // Initialize visited matrices for both grids
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> vis2(m, vector<int>(n, 0));

        // First pass: Mark all valid parts of sub-islands in grid2 that are fully covered in grid1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid1[i][j] == 1) {
                    mark(grid1, grid2, i, j, vis);
                }
            }
        }

        int ans = 0;

        // Second pass: Count the number of valid sub-islands in grid2
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Check if the cell is unvisited and part of a potential sub-island in grid2
                if (!vis2[i][j] && grid2[i][j] == 2) {
                    // If the sub-island is valid, increment the count
                    if (isSubIsland(grid2, i, j, vis2)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    // This function marks the connected component in grid2 that corresponds to the island in grid1
    void mark(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, vector<vector<int>>& vis) {
        // Boundary and visited check, also ensuring grid1[i][j] is part of an island
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid1[i][j] != 1)
            return;

        // Mark the current cell as visited
        vis[i][j] = 1;

        // If the corresponding cell in grid2 is part of an island, mark it as 2
        if (grid2[i][j] == 1) {
            grid2[i][j] = 2;
        }

        // Recur for all four possible directions
        mark(grid1, grid2, i + 1, j, vis);
        mark(grid1, grid2, i - 1, j, vis);
        mark(grid1, grid2, i, j + 1, vis);
        mark(grid1, grid2, i, j - 1, vis);
    }

    // This function checks if the marked island in grid2 is a valid sub-island
    bool isSubIsland(vector<vector<int>>& grid2, int i, int j, vector<vector<int>>& vis2) {
        // Boundary and visited check
        if (i < 0 || i >= m || j < 0 || j >= n || vis2[i][j])
            return true;

        // If we encounter a `0`, it's valid as it indicates water
        if (grid2[i][j] == 0) 
            return true; // Treat `0` as valid since it's not part of the island

        // If we encounter a `1`, it means this part of grid2 is not covered by grid1's island
        if (grid2[i][j] == 1) 
            return false; // Invalid because it's part of grid2 but not fully in grid1

        // Mark the current cell as visited
        vis2[i][j] = 1;

        // Recursively check all four directions
        bool up = isSubIsland(grid2, i - 1, j, vis2);
        bool down = isSubIsland(grid2, i + 1, j, vis2);
        bool left = isSubIsland(grid2, i, j - 1, vis2);
        bool right = isSubIsland(grid2, i, j + 1, vis2);

        // Return true only if all directions are valid
        return up && down && left && right;
    }
};
