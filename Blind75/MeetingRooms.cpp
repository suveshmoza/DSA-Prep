#include <bits/stdc++.h>
using namespace std;

bool couldAttend(vector<vector<int>> meetings){
    sort(meetings.begin(), meetings.end());
    for (int i = 0; i < meetings.size() - 1; i++){
        if (meetings[i][1] > meetings[i + 1][0])
            return false;
    }
    return true;
}

int main(){
    vector<vector<int>> meetings = {
        {0, 30},
        {30, 40},
        {40, 50}};
    if (couldAttend(meetings)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}