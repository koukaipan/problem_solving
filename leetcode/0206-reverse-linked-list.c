/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev, *next, *iter, *tmp;
    
    iter = head;
    prev = 0;
    if(!head)
        return head;
    
    while(iter->next) {
        tmp = iter->next;
        iter->next = prev;
        prev = iter;
        iter = tmp;
    }
    iter->next = prev;
    return iter;
}
