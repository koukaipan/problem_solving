/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head, int end){
    struct ListNode* prev, *next, *iter, *tmp;
    int cnt;
    
    if(!head)
        return head;
    
    iter = head;
    prev = 0;    
    cnt = 0;
    while(cnt < end && iter->next) {
        tmp = iter->next;
        iter->next = prev;
        prev = iter;
        iter = tmp;
        cnt++;
    }
    head->next = iter->next;
    iter->next = prev;
    
    return iter;
}


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* iter = head;
    struct ListNode* prev, *next, *new;
    int cnt;
    
    if (!head->next)
        return head;
    if(left == right)
        return head;
    
    prev = 0;
    for(iter = head, cnt = 1; iter && cnt < left; cnt++) {
        prev = iter;
        iter = iter->next;
    }

    new = reverseList (iter, right - left);
    if(left != 1) {
        prev->next = new;  
        return head;
    } else
        return new;
}
