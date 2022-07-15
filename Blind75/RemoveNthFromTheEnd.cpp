//! Brute 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp=head;
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    if(len==1) return NULL;
    if(len<n) return head;
    if(len==n){
        head=head->next;
        return head;
    }
    len=len-n;
    temp=head;
    while(--len){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}

//! Best

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow=head,*fast=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(!fast) return head->next;
    while(fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return head;
}