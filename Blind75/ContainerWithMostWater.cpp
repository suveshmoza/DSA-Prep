int maxArea(vector<int>& height) {
    int low=0,high=height.size()-1,maxiArea=INT_MIN;
    while(low<high){
        int minVal=min(height[low],height[high]);
        int area=minVal*(high-low);
        maxiArea=max(maxiArea,area);
        if(height[low]>height[high]){
            high--;
        }else{
            low++;
        }
    }
    return maxiArea;
}