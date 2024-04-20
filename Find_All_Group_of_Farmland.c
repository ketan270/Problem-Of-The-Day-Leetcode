int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes) {

    int m = landSize;
    int n = landColSize[0];

    int r1, c1, r2, c2;

    int * seen = calloc(sizeof(int),m * n);

    int **groups = calloc(sizeof(int*),(m * n + 1) / 2);
    *returnColumnSizes = calloc(sizeof(int),(m * n + 1) / 2);
    *returnSize = 0;    

    for(r1 = 0; r1 < m; r1++) {
        for(c1 = 0; c1 < n; c1++) {

            if((seen[r1 * n + c1] == 0) && (land[r1][c1] == 1)) {

                c2 = c1;
                while((c2 + 1 < n) && (land[r1][c2 + 1] == 1)) { c2++; }

                r2 = r1;
                while((r2 + 1 < m) && (land[r2 + 1][c1] == 1)) { r2++; }
                
                (*returnColumnSizes)[*returnSize] = 4;
                groups[*returnSize] = calloc(sizeof(int),4);
                groups[*returnSize][0] = r1;
                groups[*returnSize][1] = c1;
                groups[*returnSize][2] = r2;
                groups[*returnSize][3] = c2;
                (*returnSize)++;

                int i, j;
                for(i = r1; i <= r2; i++) {
                    for(j = c1; j <= c2; j++) {
                        seen[i * n + j] = 1;                       
                    }
                }
            }
        }
    }

    return groups;
}
