Node* merge(Node* a,Node* b){
    if(!a) return b;
    if(!b) return a;
    Node* res;
    if(a->data<=b->data){
        res=a;
        res->child=merge(a->child,b);
    }else{
        res=b;
        res->child=merge(a,b->child);
    }
    // means no more list on right side 
    // otherwise it will keep on checking right.
    res->next=NULL;
    return res;
}

Node* flattenLinkedList(Node* head) {
    if(!head||!head->next) return head;
    return merge(head,flattenLinkedList(head->next));
}