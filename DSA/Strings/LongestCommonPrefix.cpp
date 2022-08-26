//* O(strs.size*log(strs.size()))
string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(), strs.end());
    string common;
    string a = strs[0];
    string b = strs[strs.size() - 1];
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            common += a[i];
        } else {
            break;
        }
    }
    return common;
}

//* Using TRIE