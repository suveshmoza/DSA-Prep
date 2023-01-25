class TrieNode{
    public:
    TrieNode* children[26];
    int prefixCount=0;
    int endingHereCount=0;
};

class Trie{

    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }

    void insert(string &word){
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++){
            if(curr->children[word[i]-'a']==NULL){
                curr->children[word[i]-'a']=new TrieNode();
            }
            curr=curr->children[word[i]-'a'];
            curr->prefixCount+=1;
        }
        curr->endingHereCount+=1;
    }

    int countWordsEqualTo(string &word){
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++){
            if(curr->children[word[i]-'a']==NULL){
                return 0;
            }
            curr=curr->children[word[i]-'a'];
        }
        return curr->endingHereCount;
    }

    int countWordsStartingWith(string &word){
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++)
        {
           if(curr->children[word[i]-'a']==NULL)
           return 0;
           curr=curr->children[word[i]-'a'];
        }
        return curr->prefixCount;
    }

    void erase(string &word){
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++)
        {
            curr=curr->children[word[i]-'a'];
            curr->prefixCount-=1;
        }
        curr->endingHereCount-=1;
    }
};
