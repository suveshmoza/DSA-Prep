int findDuplicate(vector<int>& arr) {
        int ans;
        for(int i=0;i<arr.size();i++){
            if(arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            }
            else ans = abs(arr[i]);
        }
    return ans;
}


//------------------------------------

int findDuplicate(vector<int>& nums) {
    int slow=nums[0];
    int fast=nums[nums[0]];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    fast=0;
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}