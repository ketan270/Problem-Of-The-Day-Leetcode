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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return NULL;

        queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false; 

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodesAtLevel;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                nodesAtLevel.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (isOddLevel) {
                int left = 0, right = nodesAtLevel.size() - 1;
                while (left < right) {
                    swap(nodesAtLevel[left]->val, nodesAtLevel[right]->val);
                    left++;
                    right--;
                }
            }

            isOddLevel = !isOddLevel;
        }

        return root;
    }
};
