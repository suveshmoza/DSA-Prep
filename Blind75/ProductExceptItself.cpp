vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int>prefix(n,0),suffix(n,0);
    prefix[0]=1,suffix[n-1]=1;
    vector<int>res(n);
    
    for(int i=1;i<n;i++){
        prefix[i]=nums[i-1]*prefix[i-1];
    }
    
    for(int i=n-2;i>=0;i--){
        suffix[i]=nums[i+1]*suffix[i+1];
    }
    
    for(int i=0;i<n;i++){
        res[i]=suffix[i]*prefix[i];
    }
    
    return res;
}


vector<int> spiralOrder(vector<vector<int>>& mat) {
    int totalRows=mat.size(),totalCols=mat[0].size();
    int row=0,col=0;
    vector<int>res;
    
    while(row<totalRows&&col<totalCols){
      for(int i=col;i<totalCols;i++){
          res.push_back(mat[row][i]);
      }
        row++;
      for(int i=row;i<totalRows;i++){
          res.push_back(mat[i][totalCols-1]);
      }
        totalCols--;
        
        if(row<totalRows){
            for(int i=totalCols-1;i>=col;i--){
                res.push_back(mat[totalRows-1][i]);
            }
            totalRows--;
        }
        if(col<totalCols){
            for(int i=totalRows-1;i>=row;i--){
                res.push_back(mat[i][col]);
            }
            col++;
        }
    }        
    return res;
}