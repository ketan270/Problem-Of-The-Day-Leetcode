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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getLength(head);
        int extra = len % k;  // extra nodes to add in the start
        int bucket = len / k;  // each bucket size
        vector<ListNode*> result;

        ListNode* ptr = head;

        while (ptr) {
            result.emplace_back(ptr);
            int skip = bucket + (extra-- > 0 ? 1 : 0);  // how many places to skip to get proper bucket size
            while (ptr && --skip > 0) {
                ptr = ptr->next;
            }
            ListNode* tmp = ptr->next;
            ptr->next = nullptr;
            ptr = tmp;
        }

        while (result.size() != k) {
            result.emplace_back(nullptr);
        }

        return result;
    }
private:
    int getLength(ListNode* head) {
        ListNode* ptr = head;
        int len = 0;

        while (ptr) {
            ptr = ptr->next;
            len++;
        }

        return len;
    }
};
