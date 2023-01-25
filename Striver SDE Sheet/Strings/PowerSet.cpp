vector<vector<int>> res;
vector<int> temp;

void solve(vector<int> v, int index) {
    res.push_back(temp);
    for (int i = index; i < v.size(); i++) {
        temp.push_back(v[i]);
        solve(v, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> pwset(vector<int> v) {
    solve(v, 0);
    return res;
}