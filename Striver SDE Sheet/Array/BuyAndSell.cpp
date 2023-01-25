int find(vector<int> &prices, int i,int k,bool buy,vector<vector<int>> &dp){
    if(i>=prices.size()||k<=0) return 0;
    if(dp[i][buy]!=-1) return v[i][buy];
    if(buy){  
       return dp[i][buy]=max(-prices[i]+find(prices,i+1,k,!buy,v),find(prices,i+1,k,buy,v)); 
    }
    else{
       return dp[i][buy]=max( prices[i]+find(prices,i+1,k-1,!buy,v),find(prices,i+1,k,buy,v)); 
    }
}
int maxProfit(vector<int>& prices) {
    int n=prices.size(); 
    vector<vector<int>> dp(n,vector<int> (2,-1));
    return find(prices,0,1,1,v);
}

//------------------------------

int maxProfit(vector<int>& prices) {
    int minPrice=INT_MAX,maxProfit=0;
    int n=prices.size();
    for(int i=0;i<n;i++){
        minPrice=min(minPrice,prices[i]);
        maxProfit=max(maxProfit,prices[i]-minPrice);
    }
    return maxProfit;
}