
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    vector<int>res;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>st;
    
    pq.push(make_pair(a[n-1]+b[n-1],make_pair(n-1,n-1)));
    st.insert(make_pair(n-1,n-1));
    
    for(int count=0;count<k;count++){
        auto temp=pq.top();
        pq.pop();
        res.push_back(temp.first);
        int i=temp.second.first;
        int j=temp.second.second;
        
        pair<int,int>temp1=make_pair(i-1,j);
        if(st.find(temp1)==st.end()){
            pq.push(make_pair(a[i-1]+b[j],make_pair(i-1,j)));
            st.insert(temp1);
        }
        
        temp1=make_pair(i,j-1);
        if(st.find(temp1)==st.end()){
            pq.push(make_pair(a[i]+b[j-1],make_pair(i,j-1)));
            st.insert(temp1);
        }
    }
    return res;
}