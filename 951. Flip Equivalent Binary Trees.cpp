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
    
    
    bool check(TreeNode* n1,TreeNode* n2){
        if (!n1 && !n2) return true;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;
        
        
        bool dontflip = (check(n1->left,n2->left) && check(n1->right,n2->right)) ;
        bool flip= (check(n1->left,n2->right) && check(n1->right,n2->left)) ;
        
        return flip or dontflip;
        
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        return check(root1,root2);
    }
};
