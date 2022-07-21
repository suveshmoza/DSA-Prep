//! O(n^2) 
int search(vector<int>&inorder,int start,int end,int x){
    int res;
    for(int i=start;i<=end;i++){
        if(inorder[i]==x){
            res=i;
            break;
        }
    }
    return res;
}

TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int start,int end,int &preIndex){
    if(start>end) return NULL;
    TreeNode* root=new TreeNode(preorder[preIndex++]);
    if(start==end) return root;
    int newIndex=search(inorder,start,end,root->val);
    root->left=helper(preorder,inorder,start,newIndex-1,preIndex);
    root->right=helper(preorder,inorder,newIndex+1,end,preIndex);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex=0;
    return helper(preorder,inorder,0,inorder.size()-1,preIndex);
}


//! O(n)
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map <int, int> umap;
    for (int i=0; i<inorder.size(); i++) umap[inorder[i]]=i;
    return buildTreeUtil (preorder, inorder, 0, inorder.size()-1, 0, umap);
}
TreeNode* buildTreeUtil (vector<int>& preorder, vector<int>& inorder, int iStart, int iEnd, int preInd, unordered_map <int, int>& umap) {
    if (preInd>=preorder.size() || iStart>iEnd) return NULL;
    TreeNode* root=new TreeNode(preorder[preInd]);
    
    int inInd=umap[preorder[preInd]];
    int numbersOnLeft=inInd-iStart;
    root->left=buildTreeUtil (preorder, inorder, iStart, inInd-1, preInd+1, umap);
    root->right=buildTreeUtil (preorder, inorder, inInd+1, iEnd, preInd+1+numbersOnLeft, umap);
    return root;
} 
