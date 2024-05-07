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
    ListNode* doubleIt(ListNode* head) {
        if (!head) {
        return nullptr;
    }

    std::stack<int> values;
    ListNode* current = head;
    while (current) {
        values.push(current->val);
        current = current->next;
    }

    current = nullptr; // Reset current pointer
    int carry=0;
    while (!values.empty()) {
        int doubled_val = values.top() * 2+carry;
        if(doubled_val>9)
        {
          carry=1;
        }
      else
      {
        carry=0;
      }
        values.pop();

        if (!current) {
            current = new ListNode(doubled_val % 10);
        } else {
            ListNode* new_node = new ListNode(doubled_val % 10);
            new_node->next = current;
            current = new_node;
        }

        
    }
      if(carry==1)
      {
        ListNode* new_node = new ListNode(1);
            new_node->next = current;
            current = new_node;
      }

    return current;
    }
};
