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