ListNode* reverse(ListNode* head){
    ListNode *prev=NULL,*curr=head,*next=head;
    while(curr){
        next=next->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    ListNode *slow=head,*fast=head;
    
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    slow=reverse(slow);
    fast=head;
    while(slow&&fast){
        if(slow->val!=fast->val){
            return false;
        }
        slow=slow->next;
        fast=fast->next;
    }
    return true;
}