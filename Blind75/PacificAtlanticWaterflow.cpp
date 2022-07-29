void dfs(vector<vector<int>>&h,vector<vector<bool>>&vis,int i,int j,int n,int m){
    vis[i][j]=true;
    if (i-1 >= 0 && vis[i-1][j] != true && h[i-1][j] >= h[i][j])
        dfs(h, vis, i-1, j,n,m);
    if (i+1 < n && vis[i+1][j] != true && h[i+1][j] >= h[i][j])
        dfs(h, vis, i+1, j,n,m);
    if (j-1 >= 0 && vis[i][j-1] != true && h[i][j-1] >= h[i][j])
        dfs(h, vis, i, j-1,n,m);
    if (j+1 < m && vis[i][j+1] != true && h[i][j+1] >= h[i][j])
        dfs(h, vis, i, j+1,n,m);    
}
    
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>>res;
    int n=heights.size(),m=heights[0].size();
    vector<vector<bool>>pacific(n,vector<bool>(m)),atlantic(n,vector<bool>(m));   
    for(int i=0;i<n;i++){
        dfs(heights,pacific,i,0,n,m);
        dfs(heights,atlantic,i,m-1,n,m);
    }
    for(int j=0;j<m;j++){
        dfs(heights,pacific,0,j,n,m);
        dfs(heights,atlantic,n-1,j,n,m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(atlantic[i][j]&&pacific[i][j]){
                res.push_back({i,j});
            }
        }
    }
    return res;
}