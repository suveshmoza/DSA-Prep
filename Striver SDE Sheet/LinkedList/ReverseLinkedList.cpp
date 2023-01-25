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