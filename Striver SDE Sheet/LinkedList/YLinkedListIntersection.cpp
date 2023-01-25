ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ogHeadA=headA,*ogHeadB=headB;
    while(headA!=headB){
        if(headA==NULL){
            headA=ogHeadB;
        }else{
                        headA=headA->next;
        }
        if(headB==NULL){
            headB=ogHeadA;
        }else{
        headB=headB->next;
        }
    }
    return headA;
}

// Another approach is by using the difference of lists length
// and starting the list(longer one) at start position + length_diff