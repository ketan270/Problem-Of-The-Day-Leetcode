class Solution {
public:
    bool check(vector<vector<int>> &v, int i, int j){
        int cnt=1;

        map<int,int> mp;
        mp[v[i][j]]++, mp[v[i][1+j]]++, mp[v[i][2+j]]++;
        mp[v[i+1][j]]++, mp[v[i+1][j+1]]++, mp[v[i+1][j+2]]++;
        mp[v[2+i][j]]++, mp[v[2+i][j+1]]++, mp[v[2+i][j+2]]++;

        if(mp.size() != 9) return 0;
        for(auto it : mp){
            if(it.first >= 10 or it.first <= 0) return 0;
        }

        int k = v[i][j] + v[i][1+j] + v[i][2+j];
        if(v[i+1][j] + v[i+1][j+1] + v[i+1][j+2] == k) cnt++;
        if(v[2+i][j] + v[2+i][j+1] + v[2+i][j+2] == k) cnt++;

        if(v[i][j] + v[i+1][1+j] + v[i+2][j+2] == k) cnt++; // dia
        if(v[i][2+j] + v[i+1][1+j] + v[i+2][j] == k) cnt++; // dia

        if(v[i][j] + v[i+1][j] + v[i+2][j] == k) cnt++;
        if(v[i][1+j] + v[1+i][1+j] + v[i+2][j+1] == k) cnt++;
        if(v[i][2+j] + v[i+1][2+j] + v[i+2][j+2] == k) cnt++;

        cout << cnt << endl;

        return cnt==8;
    }
    int numMagicSquaresInside(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
 
        int ans = 0;
        for(int i =0; i <= n-3; i++){
            for(int j=0; j <= m-3; j++){
                if(check(v,i,j)) ans++;
            }
            cout << endl;
        }

        return ans;
    }
};
