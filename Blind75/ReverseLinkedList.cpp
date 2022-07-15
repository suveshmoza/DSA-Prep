//! Recursive
ListNode* helper(ListNode* head ,ListNode* prev){
    if(!head) return prev;
    ListNode *next=head->next;
    head->next=prev;
    return helper(next,head);
}
    
ListNode* reverseList(ListNode* head) {
    return helper(head,NULL);
}

//! Iterative
ListNode* reverseList(ListNode* head) {
    ListNode *prev=NULL,*next=head,*curr=head;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}