Node* helper(Node* root,int key){
	if(!root) return new Node(key);
	if(key<=root->data){
		root->left=helper(root->left,key);
	}else{
		root->right=helper(root->right,key);
	}
	return root;
}

Node* insertBst(Node* root, int key) {
    return helper(root,key);
}