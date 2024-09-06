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
    bool bs(vector<int> &nums, int k){
        int l =0;
        int h =nums.size()-1;
        while(l<=h){
            int m = h + (l-h)/2;
            if(nums[m]==k){
                return true;
            }
            else if(nums[m]<k){
                l=m+1;
            }
            else{
                h = m-1;
            }
        }
        return false;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(),nums.end());
        ListNode* temp = head;
        ListNode* curr = temp;
        while(temp->next!= nullptr){
            
            if(bs(nums,temp->next->val)){
                cout<<temp->val<<endl;
                ListNode* x = temp->next;
                temp->next = temp->next->next;
                delete x;
            }
            else{
                temp = temp -> next;
            }
        }
        //Below code for the 1st element of linked-list, the above 
        // "while loop" skips the first element
        if(bs(nums,curr->val)){
            ListNode* y= curr;
            curr = curr->next;
            delete y;
        }
        return curr;
    }
};
