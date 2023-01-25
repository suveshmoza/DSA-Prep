void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i=m, j=0;i<m+n, j<n;i++, j++){
        nums1[i] = nums2[j];
    }
    int gap = ceil((m+n)/2);
    int p1, p2;
    while(gap>0){
        p1 = 0;
        p2 = gap;
        while(p2 < m+n){
            if(nums1[p1] > nums1[p2]){
                swap(nums1[p1], nums1[p2]);
            }
            p1++;
            p2++;
        }
        if(gap == 1){
            break;
        }
        gap = ceil(float(gap)/2);
    }
}