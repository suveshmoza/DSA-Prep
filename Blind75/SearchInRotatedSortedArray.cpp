int search(vector<int>& nums, int target) {
    int low=0,high=nums.size()-1,index=-1;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[low]<=nums[mid]){
            if(nums[low]<=target&&target<=nums[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(nums[high]>=target&&nums[mid]<=target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }        
    return index;
}