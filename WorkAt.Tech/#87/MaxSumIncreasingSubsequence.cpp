int maxSumSubsequence(vector<int> &arr) {
	int n=arr.size();
    int dp[n+1];
	for(int i=0;i<n;i++) dp[i]=arr[i];
	
	int sum=0;
	for(int i=0;i<n;i++){
	    for(int j=0;j<i;j++){
	        if(arr[i]>arr[j]&&dp[i]<dp[j]+arr[i]){
	            dp[i]=dp[j]+arr[i];
	        }
	    }
	}
	for(int i=0;i<n;i++){
	    sum=max(sum,dp[i]);
	}
	
	return sum;
}