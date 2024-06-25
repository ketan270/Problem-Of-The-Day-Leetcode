/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v){
        if(!root) return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    void replace(TreeNode* &root, vector<int> v){
        if(!root) return;

        replace(root->left, v);
        int sum=root->val;
        for(int i=0; i<v.size(); i++){
            if(v[i]>root->val){
                sum+=v[i];
            }
        }
        root->val=sum;
        replace(root->right, v);
    }
    
    void solve(TreeNode* &root, int& greaterSum){
        if(!root) return;

        solve(root->right, greaterSum);
        root->val+=greaterSum;
        greaterSum=root->val;
        solve(root->left, greaterSum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        // //store inorder traversal of bst in a vector --- sorted
        // vector<int> v;
        // inorder(root, v);

        // //replace nodes values with help of this vector
        // replace(root, v);
        // return root;

        int greaterSum=0;
        solve(root, greaterSum);
        return root;
    }
};
