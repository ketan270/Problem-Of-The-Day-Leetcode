class Solution {
public:
    using int2=pair<int, int>;
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<int2> sIdx(n);
        for(int i=0; i<n; i++)
            sIdx[i]={score[i], i};
        sort(sIdx.rbegin(), sIdx.rend());
        vector<string> ans(n);
        ans[sIdx[0].second]="Gold Medal";
        if( n>1) ans[sIdx[1].second]="Silver Medal";
        if (n>2) ans[sIdx[2].second]="Bronze Medal";
        for(int i=3; i<n; i++)
            ans[sIdx[i].second]=to_string(i+1);
        return ans;
    }
};
