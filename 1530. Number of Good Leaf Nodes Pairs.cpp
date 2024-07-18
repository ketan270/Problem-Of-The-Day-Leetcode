int init = [](){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return -1;
}();

class Solution {
public:
    vector<int> dfs(TreeNode* root, int &d, int &ans) {
        if (!root) return {};
        if (!root->left && !root->right) return {1};
        
        vector<int> l = dfs(root->left, d, ans), r = dfs(root->right, d, ans), arr;
        
        for (auto &x : l) 
            for (auto &y : r) 
                if (x + y <= d) ans++;
                
        for (auto &x : l) arr.push_back(x + 1);
        for (auto &x : r) arr.push_back(x + 1);
        
        return arr;
    }
    
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
};
