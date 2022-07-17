ListNode* merge2Lists(ListNode* first,ListNode* second){
    if(first==NULL) return second;
    if(second==NULL) return first;
    ListNode* res;
    if(first->val<=second->val){
        res=first;
        res->next=merge2Lists(first->next,second);
    }else{
        res=second;
        res->next=merge2Lists(first,second->next);
    }
    return res;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return NULL;
    ListNode* head = lists[0];
    for (int i = 1; i < lists.size(); i++)
        head = merge2Lists(head, lists[i]);
    return head;
}