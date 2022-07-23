//! 🤯

class TrieNode{
public:
    bool end;
    string word;
    TrieNode* children[26];
    TrieNode(){
        end = false;
        word = "";
        for(int i = 0 ; i < 26 ; ++i){
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    
     void insert(string word,TrieNode* root){
        TrieNode* temp = root;
        for(int i = 0 ; i < word.length() ; ++i){
            int k = word[i] - 'a';
            if(temp->children[k] == NULL)
                temp->children[k] = new TrieNode();
            temp = temp->children[k];
        }
        temp->end = true;
        temp->word = word;
    }
    
    vector<string> v;
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    
     void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root ){
        int m = board.size() , n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#' )
            return ;
        int k = board[i][j] - 'a';
        if(root->children[k] == NULL)return;
        root = root->children[k];
        if(root->end == true){
            v.push_back(root->word);
            root->end = false;//avoid duplicacy
        }
        char c = board[i][j];
        board[i][j] = '#';
        for(int d = 0 ; d < 4 ; ++d){
            int xx = i + dir[d][0], yy = j + dir[d][1];
            dfs(board,xx,yy,root);
        }
        board[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size() , n = board[0].size();
        TrieNode* root = new TrieNode();
        for(string w : words)
            insert(w,root);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,i,j,root);
            }
        }
        return v;
    }
};