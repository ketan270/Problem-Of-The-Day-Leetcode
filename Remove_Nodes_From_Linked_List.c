/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head){ // reverse linkedlist
    if(!head || !head->next){ // if the linkedlist is size one or zero just return it
        return head;
    }
    struct ListNode* curr = head;  // create a current node 
    curr=curr->next; // increment it 
    head->next = NULL; // set the first head node's next to null
    while(curr->next){ // while current node has a next value(not at tail)
        struct ListNode* next = curr->next;// next is equivalent to node after curr
        curr->next = head; // set the next value to head(our past value)
        head=curr; // update past value and current value to next values
        curr = next;
    }
    curr->next = head; // at the tail, set the next value just to current value
    return curr; // return previous tail , new head

}
struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode* temp = reverse(head); // create a new listnode pointing toward the head of the reversed linkedlist
    struct ListNode* res = temp ;  // head of the reversed linkedlist
    while(temp->next){ // traverse through the new linked list
        if(temp->val > temp->next->val){ // if the current value is greater than the next one, skip the next one 
            temp->next = temp->next->next; 
        }
        else{
            temp=temp->next;// else traverse to next node
        }
    }
    return reverse(res); // return the increasing linkedlist in reverse
    
}
