typedef pair<int, int> p;
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<p> mp(m*n + 1); 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowColorCount(m), colColorCount(n);

        for(int i = 0; i < arr.size(); i++){
            int value = arr[i];
            int row = mp[value].first, col = mp[value].second;
            
            if(++rowColorCount[row] == n || ++colColorCount[col] == m) return i;
        }

        return -1;
        
    }
};
