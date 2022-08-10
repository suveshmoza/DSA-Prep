ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    ListNode *newHead,*tail;
    newHead=head;
    tail=head;
    int len=1;
    while(tail->next){
        len++;
        tail=tail->next;
    }
    tail->next=head;
    if(k%=len){
        for(int i=0;i<len-k;i++){
            tail=tail->next;
        }
    }
    newHead=tail->next;
    tail->next=NULL;
    return newHead;
}