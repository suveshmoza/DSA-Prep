int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char dir[4]={'U','D','L','R'};
void solve(vector<vector<int>>&maze,int i,int j,int N,int M,vector<string>&res,string temp){
    if(i<0||i>=N||j<0||j>=M||maze[i][j]==0) return;    
    if(i==N-1&&j==M-1){
        res.push_back(temp);
        return;
    }
    maze[i][j]=0;
    for(int k=0;k<4;k++){
        solve(maze,i+dx[k],j+dy[k],N,M,res,temp+dir[k]);
    }
    maze[i][j]=1;
}

vector<string> findPath(vector<vector<int>> &maze, int n) {
    vector<string>res;
    solve(maze,0,0,maze.size(),maze[0].size(),res,"");
    return res;
}