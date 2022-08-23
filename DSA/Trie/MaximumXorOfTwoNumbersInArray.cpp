class Trie{
    public:
        Trie* child[2];
};
Trie* root;

void insert(int num){
    Trie* curr=root;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(curr->child[bit]==NULL){
            curr->child[bit]=new Trie();
        }
        curr=curr->child[bit];
    }
}

int search(int num){
    Trie* curr=root;
    int ans=0;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(curr->child[1-bit]!=NULL){
            ans=ans|1<<i;
            curr=curr->child[1-bit];
        }else{
            curr=curr->child[bit];
        }
    }
    return ans;
}

int maximumXor(vector<int> A){
    root=new Trie();
    for(auto i:A){
        insert(i);
    }
    int ans=0;
    for(auto i:A){
        ans=max(ans,search(i));
    }
    return ans;
}