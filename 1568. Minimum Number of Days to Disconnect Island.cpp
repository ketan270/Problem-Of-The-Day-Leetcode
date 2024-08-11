class Solution {
    private:
    void dfs(vector<vector<int>>& temp, int i, int j){
        if(i < 0 || j < 0 || i >= temp.size() || j >= temp[i].size() || temp[i][j] == 0) return;

        if(temp[i][j])
        temp[i][j] = 0;
        dfs(temp, i+1, j);
        dfs(temp, i, j+1);
        dfs(temp, i-1, j);
        dfs(temp, i, j-1);
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int cnt =0;
        vector<vector<int>> temp(grid.begin(), grid.end());
        for(int i =0; i < temp.size(); ++i){
            for(int j =0; j < temp[i].size(); ++j){
                if(temp[i][j] == 1){
                    dfs(temp, i, j);
                    cnt++;
                }
            }
        }
        if(cnt > 1 || cnt == 0) return 0;
        cnt =0;
        for(int i =0; i < grid.size(); ++i){
            for(int j =0; j < grid[i].size(); ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    cnt =0;
                    // temp.erase();
                    // temp.resize(grid.begin(), grid.end());
                    temp = grid;
                    for(int k =0; k < temp.size(); ++k){
                        for(int p =0; p < temp[k].size(); ++p){
                            if(temp[k][p] == 1){
                                dfs(temp, k, p);
                                cnt++;
                            }
                        }
                    }
                    grid[i][j] = 1;
                    if(cnt > 1 || cnt == 0) return 1;
                }
            }
        }
        return 2;


    }
};
