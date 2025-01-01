class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int> pref(n,0);
        int zero=0;
        for(int i=0;i<n;i++){
            if(s[i] == '0') zero++;
            pref[i]=zero;
        }
        vector<int> suff(n,0);
        int one=0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1') one++;
            suff[i]=one;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,pref[i]+suff[i+1]);
        }
        return ans;
    }
};
