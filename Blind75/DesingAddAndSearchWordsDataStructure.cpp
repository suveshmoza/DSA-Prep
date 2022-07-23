class WordDictionary {
private:
    struct TrieNode{
        TrieNode *nxt[26];
        bool ended;
    };
    TrieNode* node;

public:
    WordDictionary() {
        node=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=node;
        for(int i=0;i<word.size();i++){
            if(curr->nxt[word[i]-'a']==NULL) curr->nxt[word[i]-'a']=new TrieNode();
            curr=curr->nxt[word[i]-'a'];
        }
        curr->ended=true;
    }
    
    bool helper(string word,int index,TrieNode* node){
        if(index==word.size()) return node->ended;
        char currChar=word[index];
        if(currChar!='.'){
            if(node->nxt[currChar-'a']){
                return helper(word,index+1,node->nxt[currChar-'a']);
            }
            return false;
        }
        
        for(int i=0;i<26;i++){
            if(node->nxt[i]!=NULL)
                if(helper(word,index+1,node->nxt[i])) return true;
        }
        return false;
    }
    
    bool search(string word) {
        return helper(word,0,node);
    }
};