class Solution {
public:
    void traverse(TreeNode* root, int level, vector<int>& res) {
        if (root == nullptr) return;

        if (res.size() <= level) {
            res.push_back(root->val);
        } else {
            res[level] = max(res[level], root->val);
        }
        traverse(root->left, level+1, res);
        traverse(root->right, level+1, res);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        
        traverse(root, 0, res);
        return res;
    }
};
