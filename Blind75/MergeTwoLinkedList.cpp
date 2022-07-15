ListNode* helper(ListNode* a,ListNode* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    ListNode* res;
    if(a->val<b->val){
        res=a;
        res->next=helper(a->next,b);
    }
    else{
        res=b;
        res->next=helper(a,b->next);
    }
    return res;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    return helper(list1,list2);
}