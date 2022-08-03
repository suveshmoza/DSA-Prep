class Trie {

private:
    struct TrieNode{
        TrieNode* nxt[26];
        bool isEnd;
    };
    TrieNode* node;
public:
    Trie() {
        node=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=node;
        for(int i=0;i<word.size();i++){
            if(curr->nxt[word[i]-'a']==NULL){
                curr->nxt[word[i]-'a']=new TrieNode();
            }
            curr=curr->nxt[word[i]-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* curr=node;
        for(int i=0;i<word.size();i++){
            if(curr->nxt[word[i]-'a']==NULL) return false;
            curr=curr->nxt[word[i]-'a'];
        }
        if(curr->isEnd==true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
    TrieNode* curr=node;
    for(char c: prefix){
        if(curr->nxt[c-'a']==NULL)return false;
        curr=curr->nxt[c-'a'];
    }
        return true;
    }
};