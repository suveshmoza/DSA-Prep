void printLinkedListReverse (ListNode* head) {
	if(head==NULL){
		return;
	}
	printLinkedListReverse(head->next);
	cout<<head->data<<" ";
}