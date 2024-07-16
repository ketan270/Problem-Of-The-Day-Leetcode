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
    TreeNode* FindLca(TreeNode* root,int startValue,int destValue)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->val == startValue || root->val == destValue)
        {
            return root;
        }

        TreeNode* leftans=FindLca(root->left, startValue, destValue);
        TreeNode* rightans=FindLca(root->right, startValue, destValue);

        if(leftans && rightans)
        {
            return root;
        }        
        
        return leftans ? leftans : rightans;

    }
    bool Findpath(TreeNode*root, int value,string &path)
    {
        if(root == NULL)
        {
            return false;
        }
        if(root->val == value)
        {
            return true;
        }
        path += 'L';
        bool leftans=Findpath(root->left,value,path);
        if(leftans)
            return true;
        path.pop_back();

        path+='R';
        bool rightans=Findpath(root->right,value,path);
        if(rightans)return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA=FindLca(root,startValue,destValue);
        
        string LcaToStart,LcaToDest;
        Findpath(LCA,startValue,LcaToStart);
        Findpath(LCA,destValue,LcaToDest);

        for(auto& i:LcaToStart)
        {
            i='U';
        }
        return LcaToStart+LcaToDest;
    }
};
