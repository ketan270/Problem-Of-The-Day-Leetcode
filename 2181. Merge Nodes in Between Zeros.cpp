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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* t = head->next;
        int sum = 0;
        ListNode* prev = head;
        while(t->next != nullptr){
            if(t->val != 0)
                sum += t->val;
            else
            {
                t->val = sum;
                prev->next = t;
                prev = t;
                sum = 0;
            }
            t=t->next;
        }
        prev->next = t;
        t->val = sum;
        return head->next;
    }
};

static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    return 0;
}();
