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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int dir[4][2] = {{0,1}, {1,0},{0,-1},{-1,0}};
        vector<vector<int>> res(m, vector<int>(n, -1));
        int curr = 0;
        int i =0, j=0;

        for(; head!=NULL; head = head->next){
            res[i][j] = head->val;
            int nRow = i+dir[curr][0];
            int nCol = j+dir[curr][1];
            if(nRow<0 || nCol<0 || nRow>=m || nCol>=n || res[nRow][nCol]!=-1){
                curr = (curr+1)%4;
               
            }
             i += dir[curr][0];
                j += dir[curr][1];
        }
        return res;
    }
};
