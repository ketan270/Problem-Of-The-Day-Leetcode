class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        vector<int>row(matrix.size(),INT_MAX) , col(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                row[i] = min(row[i],matrix[i][j]);
                col[j] = max(col[j],matrix[i][j]);
            }
        }
        set<int> S;
        vector<int> V;
        for(auto i:row)S.insert(i);
        for(auto i:col)
        if(S.find(i)!=S.end())V.emplace_back(i);
        return V;
    }
};
