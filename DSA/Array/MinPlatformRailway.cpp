int findPlatform(int arr[], int dep[], int n){
	sort(arr,arr+n);
	sort(dep,dep+n);
	int countPlatforms=1;
	int maxPlatforms=1;
	int i=1,j=0;
	while(i<n){
	    if(arr[i]>dep[j]){
	        countPlatforms--;
	        j++;
	    }else{
	        countPlatforms++;
	        i++;
	    }
	    maxPlatforms=max(maxPlatforms,countPlatforms);
	}
	return maxPlatforms;
}