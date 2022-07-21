bool dfs(vector<vector<char>>&board,string word,int i,int j,int index){
    if(board[i][j]==word[index]){
        char temp=board[i][j];
        board[i][j]='0';
        if(index==word.length()-1){
            return true;
        }
        if(i-1>=0){
            if(dfs(board,word,i-1,j,index+1)){
                return true;
            }
        }
        if(i+1<board.size()){
           if(dfs(board,word,i+1,j,index+1)){
               return true;
            }
        }
       if(j-1>=0){
            if(dfs(board,word,i,j-1,index+1)){
                return true;
            }
        }
        if(j+1<board[0].size()){
            if(dfs(board,word,i,j+1,index+1)){
                return true;
            }
        }
        board[i][j]=temp;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int row=board.size(),col=board[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==word[0]){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
    }
    return false;
}