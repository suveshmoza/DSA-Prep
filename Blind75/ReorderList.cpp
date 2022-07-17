ListNode* getMid(ListNode* head){
    ListNode *slow=head,*fast=head;
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head){
    ListNode *cur,*prev;
    cur=head;
    prev = NULL;
    while(cur!=NULL)
    {
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
} 

void reorderList(ListNode* head) {
    if(!head||!head->next||!head->next->next) return;
    ListNode* mid=getMid(head);
    ListNode* second=mid->next;
    mid->next=NULL;
    second=reverse(second);
    // Reorder as per question
    while(head!=NULL&&second!=NULL){
        ListNode* temp=head->next;
        head->next=second;
        second=second->next;
        head->next->next=temp;
        head=temp;
    }
}