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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return buildbst(0,v.size()-1,v);
 }
  void inorder(TreeNode* root,vector<int> & v)
  {
    if(root==NULL)
    return;

    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
    return;
  }
  TreeNode* buildbst(int start,int end,vector<int> &v)
  {
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
   
    TreeNode* root=new TreeNode(v[mid]);
    
    root->left=buildbst(start,mid-1,v);
    root->right=buildbst(mid+1,end,v);

    return root;
  }
};
