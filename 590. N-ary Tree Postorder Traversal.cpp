/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
// lrn
    void postordertraverse(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        for(auto i: root->children){
            postordertraverse(i,ans);
        }

        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postordertraverse(root, ans);
        return ans;
    }
};
