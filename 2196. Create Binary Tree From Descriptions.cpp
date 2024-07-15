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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>childi;
        for(int i=0;i<descriptions.size();i++){
            int child=descriptions[i][1];
            int left=descriptions[i][2];
                if(mpp.count(descriptions[i][0])==0){
                    mpp[descriptions[i][0]]=new TreeNode(descriptions[i][0]);
                }
               if(mpp.count(child)==0){
                    mpp[child]=new TreeNode(child);
                }
                if(left==1){
                    mpp[descriptions[i][0]]->left=mpp[child];
                }
                else{
                      mpp[descriptions[i][0]]->right=mpp[child];
                }
                childi.insert(child);
        }
        for(int i=0;i<descriptions.size();i++){
            int parent= descriptions[i][0];
    if(childi.find(parent)!=childi.end()){
        continue;
    }
    else{
        return mpp[parent];
    }
        }
        return 0;
    }
};
