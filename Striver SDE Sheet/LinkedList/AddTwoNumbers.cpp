Node *addTwoNumbers(Node *head1, Node *head2){
    int carry=0;
    Node* dummy=new Node(0);
    Node* res=dummy;
    while(head1||head2){
        int sum=carry+(head1?head1->data:0)+(head2?head2->data:0);
        Node* temp=new Node(sum%10);
        res->next=temp;
        carry=sum/10;
        if(head1)head1=head1->next;
        if(head2)head2=head2->next;
        res=res->next;
    }
    if(carry>0){
        Node* temp=new Node(carry);
        res->next=temp;
    }
    return dummy->next;
}