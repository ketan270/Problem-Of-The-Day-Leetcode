//postorder means 
// left   right   root
//call 1   call2   kaam
class Solution {
public:
    void postorder(TreeNode *root,vector<int>& ans)
   {
       //base case
       if(root==NULL) return;

    
       //call 1
       postorder(root->left,ans);
        //call 2
       postorder(root->right,ans);
        //kaam
       ans.push_back(root->val);
      

   }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};
