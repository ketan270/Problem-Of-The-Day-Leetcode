/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(TreeNode* root,ListNode* head){
        if(head==0)return 1;
        if(root==0&&head!=0)return 0;
        if(root->val==head->val){
            return solve(root->left,head->next)||solve(root->right,head->next);
        }
        return 0;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==0)return 1;
        if(root==0&&head!=0){
            return 0;
        }bool x=false;
        if(root->val==head->val){
             x= solve(root->left,head->next)||solve(root->right,head->next);
        }
        if(x)return x;
        return isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};
