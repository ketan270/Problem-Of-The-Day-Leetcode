class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>matrix (m, vector<int>(n, 0));
        for (auto it: guards){
            matrix[it[0]][it[1]] = -1;
        }
        for (auto it: walls){
            matrix[it[0]][it[1]] = -2;
        }
        for (int i = 0; i < m; i++){
            bool not_guarded = true;
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == -1){
                    not_guarded = false;
                }
                else if (matrix[i][j] == -2){
                    not_guarded = true;
                }
                else{
                    if(not_guarded) matrix[i][j] ++;
                }
            }
        }
        for (int j = 0; j < n; j++){
            bool not_guarded = true;
            for (int i = 0; i < m; i++){
                if (matrix[i][j] == -1){
                    not_guarded = false;
                }
                else if (matrix[i][j] == -2){
                    not_guarded = true;
                }
                else{
                    if(not_guarded) matrix[i][j] ++;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--){
            bool not_guarded = true;
            for (int j = n - 1; j >= 0; j--){
                if (matrix[i][j] == -1){
                    not_guarded = false;
                }
                else if (matrix[i][j] == -2){
                    not_guarded = true;
                }
                else{
                    if(not_guarded) matrix[i][j] ++;
                }
            }
        }
        for (int j = n - 1; j >= 0; j--){
            bool not_guarded = true;
            for (int i = m - 1; i >= 0; i--){
                if (matrix[i][j] == -1){
                    not_guarded = false;
                }
                else if (matrix[i][j] == -2){
                    not_guarded = true;
                }
                else{
                    if(not_guarded) matrix[i][j] ++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 4) res ++;
            }
        }
        return res;
    }
};
