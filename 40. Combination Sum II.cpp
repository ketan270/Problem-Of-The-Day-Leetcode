class Solution {
public:

    void solve(int index, vector<vector<int>> &ans, vector<int> &preAns, vector<int>& candidates, int target){
        if (target == 0){
            ans.push_back(preAns);
            return;
        }
        if (target < 0){
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if (i > index && candidates[i] == candidates[i-1]) continue;
            preAns.push_back(candidates[i]);
            solve(i+1, ans, preAns, candidates, target-candidates[i]);
            preAns.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<vector<int>> ans;
        vector<int> preAns;
        sort(candidates.begin(), candidates.end());
        solve(0, ans, preAns, candidates, target);
        return ans;
    }
};
