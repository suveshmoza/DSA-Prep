//! Using Priority Queue
#include <bits/stdc++.h>
using namespace std;

int minRooms(vector<vector<int>>meetings){
    sort(meetings.begin(),meetings.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    int room=0;
    for(int i=0;i<meetings.size();i++){
        pq.push(meetings[i][1]);
        if(meetings[i][0]<pq.top()){
            room++;
        }else{
            pq.pop();
        }
    }
    return room;
}

int main() {
	vector<vector<int>>meetings={
	    {0, 30}, 
	    {5, 10}, 
	    {15, 20}
	};
    cout<<minRooms(meetings)<<endl;
    return 0;
}


//! Sort + Array
#include <bits/stdc++.h>
using namespace std;

int minRooms(vector<vector<int>>meetings){
    int n=meetings.size();
    vector<int> start;
    vector<int> end;
    for (int i=0;i<n;i++){
        start.push_back(meetings[i][0]);
        end.push_back(meetings[i][1]);
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int i=1,j=0,currRooms=0;
    int maxRooms=1;
    while (i<n&&j<n){
        if(start[i]<end[j]){
            currRooms++;
            i++;
        }
        else{
            currRooms--;
            j++;
        }
        maxRooms = max(maxRooms,currRooms);
    }
    return maxRooms+1;
}

int main() {
	vector<vector<int>>meetings={
	    {0, 30}, 
	    {5, 10}, 
	    {15, 20}
	};
    cout<<minRooms(meetings)<<endl;
    return 0;
}