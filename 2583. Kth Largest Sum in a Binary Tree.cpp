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
 // Function to calculate the sum of nodes at each level using BFS
vector<long long> levelOrder(TreeNode* root){
    vector<long long>ans; // Vector to store level sums
    if(root==NULL)return ans;
    queue<TreeNode*>q;
    q.push(root);
   // Traverse each level of the tree
    while(!q.empty()){
        int size = q.size();
        long long levelSum=0;
        for(int i = 0;i<size;i++){
            TreeNode*node = q.front();
            q.pop();
              levelSum+=node->val; // Add the node's value to the level sum
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
           
        }
        ans.push_back(levelSum);// Store the sum of the current level
    }
    return ans;
}
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
            vector<long long> levelSums = levelOrder(root);
            if(levelSums.size()<k)return -1;// If there are fewer levels than k, return -1

        
             priority_queue<long long, vector<long long>, greater<long long>> minHeap;// Min-heap to store the k largest sums

           for (long long it : levelSums){
            minHeap.push(it);// Push the current sum into the heap
            if(minHeap.size()>k){  // If the heap size exceeds k, remove the smallest element
                minHeap.pop();
            }
           }
            return minHeap.top();// The top of the heap is the kth largest sum

    }
};




