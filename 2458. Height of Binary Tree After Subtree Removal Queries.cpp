class Solution {
public:
    map<int,pair<int,int>> mp;
    map<int,priority_queue<pair<int,int>,vector<pair<int,int>>>> lv;
    int create(TreeNode *root,int level){
        if(!root) return 0;
        int l =0,r = 0;
        if(root->left) {
            l = create(root->left,level+1);
        }
        if(root->right) {
            r = create(root->right,level+1);
        }
        mp[root->val] = {max(l,r)+1,level};
        lv[level].push({max(l,r)+1,root->val});
        return max(l,r)+1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        create(root,0);
        vector<int> res;
        for(int q : queries){
            int l = mp[q].second;
            int h = mp[q].first;
            int maxH = 0;
            if(lv[l].top().second != q){
                res.push_back(l+lv[l].top().first-1);
            }else if(lv[l].size() == 1){
                res.push_back(l-1);
            }else{
                pair<int,int> tp = lv[l].top();
                lv[l].pop();
                res.push_back(l+lv[l].top().first-1);
                lv[l].push(tp);
            }
        }
        return res;
    }
};
