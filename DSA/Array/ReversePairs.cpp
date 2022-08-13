int merge(vector<int>& nums,int l,int m,int h,vector<int>&t){
    int c=0,j=m+1;
    for(int i=l;i<=m;i++){
        while(j<=h && nums[i]>2*(long)nums[j]) j++;
        c+=j-(m+1);
    }
    int i=l,k=l;
    j=m+1;
    while(i<=m && j<=h){
        if(nums[i]<=nums[j])t[k++]=nums[i++];
        else t[k++]=nums[j++];
    }
    while(i<=m)t[k++]=nums[i++];
    while(j<=h)t[k++]=nums[j++];
    for(int i=l;i<=h;i++)nums[i]=t[i];
    return c;
}

int mergesort(vector<int>& nums,int l,int h,vector<int>&t){
    int inv=0;
    if(h>l){
        int m=l+(h-l)/2;
        inv+=mergesort(nums,l,m,t);
        inv+=mergesort(nums,m+1,h,t);
        inv+=merge(nums,l,m,h,t);
    }
    return inv;
}

int reversePairs(vector<int>& nums) {
    vector<int>t(nums.size());
    return mergesort(nums,0,nums.size()-1,t);
}