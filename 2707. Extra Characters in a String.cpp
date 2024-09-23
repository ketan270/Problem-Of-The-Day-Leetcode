class Solution {
public:
    unordered_map<string,int> mp ;
    int n ;
    int f(int i , string &s , vector<int> &dp){
        if(i==n) return 0 ;
        if(dp[i] != -1) return dp[i] ;
        int ans = INT_MAX ;
        string str = "" ;
        // making string starting from i till ind which is already in map , then calling recursion for next
        for(int ind = i ; ind<n ; ind++){
            str += s[ind] ;
            if(mp.find(str) != mp.end()){
                ans = min(ans , f(ind+1 , s , dp)) ;
            }
        }
        // skipping the curr char 
        ans = min(ans , 1 + f(i+1 , s , dp)) ;
        return dp[i] = ans ;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length() ;
        for(auto it : dictionary) mp[it] ++ ;
        vector<int> dp(n,-1) ;
        return f(0,s,dp) ;
    }
};
