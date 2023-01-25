Node* copyRandomList(Node* head) {
    // Create deep copy of nodes in between
    Node *iter=head,*front=head;
    while(iter){
        front=iter->next;
        Node* copy=new Node(iter->val);
        iter->next=copy;
        copy->next=front;
        iter=front;
    }
    // Link rand pointers in deep copy
    iter=head;
    while(iter){
        if(iter->random!=NULL){
            iter->next->random=iter->random->next;
        }
        iter=iter->next->next;
    }
    // Extract deep copy out and make the list original
    iter=head;
    Node *newHead=new Node(0),*curr=newHead;
    while(iter){
        front=iter->next->next;
        curr->next=iter->next;
        iter->next=front;
        curr=curr->next;
        iter=front;
    }
    return newHead->next;
}