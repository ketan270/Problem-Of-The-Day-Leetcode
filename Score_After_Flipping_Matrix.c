#pragma GCC optimize("O3", "unroll-loops")
int matrixScore(int** grid, int r, int* gridColSize) {
    const int c = *gridColSize;
    uint8_t col1[c];
    memset(col1, 0, sizeof(col1));
    int sum = 0;
    for (register int i = 0; i < r; i++) {
        int x = 0;
        bool one = 0;
        for (register int j = 0; j < c; j++) {
            one = (grid[i][0] == 0) ^ (grid[i][j] == 1);
            x = (x << 1) + one;
            col1[j] += one;
        }
        sum += x;
    }
    for (register int i = 0; i < c; i++) {
        if (col1[i] > r / 2)
            continue;
        sum += (1 << (c - 1 - i)) * (r - 2 * col1[i]);
    }
    return sum;
}
