void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    for(int rows=0;rows<n;rows++){
        reverse(matrix[rows].begin(),matrix[rows].end());   
    }
}