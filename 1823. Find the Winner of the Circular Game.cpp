class Solution {
public:

    void solve(vector<int>&v , int index , int &ans ,int k){
        if(v.size() == 1){
            ans=v[0];
            return;
        }

        index=(index+k)%v.size();
        v.erase(v.begin()+index);

        solve(v,index,ans,k);
        return;
    }



    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k--;
        int index=0;
        int ans;

        solve(v , index , ans , k);
        return ans;
    }
};
