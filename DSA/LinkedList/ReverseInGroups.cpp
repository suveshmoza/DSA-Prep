int getLength(ListNode* head){
    int len=0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}
    
ListNode* reverseKGroup(ListNode* head, int k) {
    int len=getLength(head);
    if(len<k) return head;
    
    int count=0;
    ListNode *prev=NULL,*curr=head,*next=head;
    while(curr&&count<k){
        next=next->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL) head->next=reverseKGroup(next,k);
    return prev;
}