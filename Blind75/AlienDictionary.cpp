void topoSort(vector<int>adj[],int u,vector<bool>&visited,vector<int>&st){
    visited[u]=true;
    for(auto v:adj[u]){
        if(!visited[v]){
            topoSort(adj,v,visited,st);
        }
    }
    st.push_back(u);
}

string findOrder(string dict[], int N, int K) {
    vector<int>adj[K];
    for(int i=0;i<N-1;i++){
        string w1=dict[i],w2=dict[i+1];
        for(int j=0;j<min(w1.size(),w2.size());j++){
            if(w1[j]!=w2[j]){
                adj[w1[j]-'a'].push_back(w2[j]-'a');
                break;
            }
        }
    }
    vector<bool>visited(K,false);
    vector<int>st;
    
    for(int i=0;i<K;i++){
        if(!visited[i]){
            topoSort(adj,i,visited,st);
        }
    }
    string res;
    for(int i=K-1;i>=0;i--){
        res.push_back(st[i]+'a');
    }
    return res;
}