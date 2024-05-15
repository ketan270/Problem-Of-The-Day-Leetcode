/*
 * 2812. Find the Safest Path in a Grid
 *
 * You are given a 0-indexed 2D matrix grid of size n x n, where (r, c)
 * represents:
 *
 * A cell containing a thief if grid[r][c] = 1
 * An empty cell if grid[r][c] = 0
 * You are initially positioned at cell (0, 0). In one move, you can move to any
 * adjacent cell in the grid, including cells containing thieves.
 *
 * The safeness factor of a path on the grid is defined as the minimum manhattan
 * distance from any cell in the path to any thief in the grid.
 *
 * Return the maximum safeness factor of all paths leading to cell (n - 1, n -
 * 1).
 *
 * An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1),
 * (r + 1, c) and (r - 1, c) if it exists.
 *
 * The Manhattan distance between two cells (a, b) and (x, y) is equal to
 * |a - x| + |b - y|, where |val| denotes the absolute value of val.
 *
 * 1 <= grid.length == n <= 400
 * grid[i].length == n
 * grid[i][j] is either 0 or 1.
 * There is at least one thief in the grid.
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define FIFO_SIZE (400 * 400 + 1)

int fifo[FIFO_SIZE][2], fifo_hdr, fifo_tail;

void fifo_init() {
    fifo_hdr = 0;
    fifo_tail = 0;
}

void fifo_push(int x, int y) {
    fifo[fifo_tail][0] = x;
    fifo[fifo_tail][1] = y;
    fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
}

void fifo_pop(int* x, int* y) {
    *x = fifo[fifo_hdr][0];
    *y = fifo[fifo_hdr][1];
    fifo_hdr = (fifo_hdr + 1) % FIFO_SIZE;
}

int fifo_cnt() {
    if (fifo_tail >= fifo_hdr) {
        return fifo_tail - fifo_hdr;
    } else {
        return FIFO_SIZE - fifo_tail + fifo_hdr;
    }
}

void bfsDist(int** dist, int row, int col, int curr_dist) {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = fifo_cnt(), x, y, next_x, next_y; i; i--) {
        fifo_pop(&x, &y);

        for (int j = 0; j < 4; j++) {
            next_x = x + dir[j][0];
            next_y = y + dir[j][1];

            if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col &&
                dist[next_x][next_y] == INT_MAX) {
                dist[next_x][next_y] = curr_dist + 1;
                fifo_push(next_x, next_y);
            }
        }
    }

    if (fifo_cnt()) {
        bfsDist(dist, row, col, curr_dist + 1);
    }
}

bool isValidPath(int** dist, int row, int col, int x, int y, int safeness,
                 bool** visited) {
    int tmp, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool ans = false;

    /* Exceeds boundary */
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return false;
    }
    /* Safeness is lower than expected value or this grid has already been
       visited */
    else if (dist[x][y] < safeness || visited[x][y]) {
        return false;
    }
    /* Reached (n - 1, n - 1) */
    else if (x == row - 1 && y == col - 1) {
        return true;
    }

    /*
     * Mark this grid as visited, no need to unmark it during current process
     * because we don't want to try the same grid twice and we don't care about
     * different combinations
     */
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        if (isValidPath(dist, row, col, x + dir[i][0], y + dir[i][1], safeness, visited)) {
            ans = true;
            break;
        }
    }

    return ans;
}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize) {

    /*
     * Input:
     *  **grid
     *  gridSize
     *  *gridColSize
     */

    int **dist = (int**)malloc(sizeof(int*) * gridSize), ans, max_safeness = 0;
    bool** visited = (bool**)malloc(sizeof(bool*) * gridSize);

    /*
     * Algorithm:
     *  (1) We need to find a path with the greatest safety factor,
     *      which means we need to be as far away from thieves as possible
     *  (2) While we are searching the possible path from left top to bottom
     * right corner, we have to calculate the distance between current grid to
     * all the thieves, it is inefficient to search and calculate it again and
     * again for different combination. (3) Using BFS method to travese the path
     * from thieves to any grids, precalculate and store the minimum manhattan
     * distances of grids (4) Binary search the numbers inbetween 0 ~ max
     * safeness factor and check if there is a path exist that meets the
     * expectations.
     */

    fifo_init();

    /* Generate manhattan distance lookup table */
    for (int i = 0; i < gridSize; i++) {
        dist[i] = (int*)malloc(sizeof(int) * gridColSize[i]);
        visited[i] = (bool*)malloc(sizeof(bool) * gridColSize[i]);

        for (int j = 0; j < gridColSize[i]; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridColSize[x]; y++) {
            if (grid[x][y]) {
                dist[x][y] = 0;
                fifo_push(x, y);
            }
        }
    }

    /* BFS traverse start from any thieve, O(n^2) */
    bfsDist(dist, gridSize, gridColSize[0], 0);

    /* Find the maximum safeness */
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridColSize[x]; y++) {
            max_safeness = MAX(max_safeness, dist[x][y]);
        }
    }

    /* Binary search start from maximum safeness, O(logn) */
    for (int i = 0, j = max_safeness; i <= j;) {
        int mid = i + (j - i) / 2;

        /* Reset visit table for new process */
        for (int k = 0; k < gridSize; k++) {
            memset((void*)visited[k], 0, sizeof(bool) * gridColSize[k]);
        }

        /* Check if there is a path meets expected safeness, O(n^2) */
        if (isValidPath(dist, gridSize, gridColSize[0], 0, 0, mid, visited)) {
            ans = mid;
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
        free(dist[i]);
    }

    free(visited);
    free(dist);

    /*
     * Output:
     *  Return the maximum safeness factor of all paths leading to cell (n - 1,
     * n - 1).
     */

    return ans;
}
