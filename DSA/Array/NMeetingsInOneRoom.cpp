static bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
    
int maxMeetings(int start[], int end[], int n){
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        arr.push_back({start[i],end[i]});
    }
    sort(arr.begin(),arr.end(),comp);
    int i=0,count=1;
    for(int j=1;j<n;j++){
        if(arr[j].first>arr[i].second){
            count++;
            i=j;
        }
    }
    return count;
}