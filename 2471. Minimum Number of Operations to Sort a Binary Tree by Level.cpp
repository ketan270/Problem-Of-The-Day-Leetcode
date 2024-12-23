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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            vector<pair<int,int>> v(n);
            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                v[i] = {node->val , i};
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sort(v.begin(), v.end());
            vector<bool> vis(n, false);
            for(int i =0; i<n; i++){
                if(vis[i] || v[i].second==i) continue;
                int cyc = 0;
                int x =i;
                while(!vis[x]){
                    vis[x] = true;
                    x= v[x].second;
                    cyc++;
                }
                if(cyc>1){
                    ans += cyc-1;
                }
            }
        }
        return ans;
    }
};
