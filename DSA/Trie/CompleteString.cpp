class Trie{
    public:
    Trie* child[26];
    bool isEnd=false;
};
Trie* root;
void insert(Trie* root,string str){
    Trie* temp=root;
    for(int i=0;i<str.length();i++){
        if(temp->child[str[i]-'a']==NULL){
            temp->child[str[i]-'a']=new Trie();
        }
        temp=temp->child[str[i]-'a'];
    }
    temp->isEnd=true;
}

bool search(Trie* root,string str){
    Trie* temp=root;
    for(int i=0;i<str.length();i++){
        if(temp->child[str[i]-'a']==NULL || temp->child[str[i]-'a']->isEnd==false) return false;
        temp=temp->child[str[i]-'a'];
    }
    return true;
}


string completeString(int n, vector<string> &a){
    root=new Trie();
    for(auto i:a){
        insert(root,i);
    }
    string ans="";
    for(auto i:a){
        if(!search(root,i)) continue;
        if(i.size()==ans.size()) ans=min(ans,i);
        else if(i.size()>ans.size()) ans=i;
    }
    if(ans=="") return "None";
    return ans;
}