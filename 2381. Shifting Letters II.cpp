class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> vec(n+1,0);
        for(auto x: shifts){
            vec[x[0]]+=( x[2]?1:-1);
            vec[x[1]+1]+=( x[2]?-1:1);
        }
        for(int i=1; i<=n; i++){
            vec[i]+=vec[i-1];
        }
        string str="";
        for(int i=0; i<n; i++){
            str.push_back('a'+((int(s[i]-'a')+(vec[i]%26)+26)%26));
        }
        return str;
    }
};
