vector<int> compute(string patt) {
    vector<int> lps(patt.length());
    int j = 0, i = 1;
    while (i < patt.length()) {
        if (patt[i] == patt[j]) {
            lps[i] = j + 1;
            i++, j++;
        } else {
            if (j == 0) {
                lps[i] = 0;
                i++;
            } else {
                j = lps[j - 1];
            }
        }
    }
    return lps;
}

int minCharsforPalindrome(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    string cnct = str + "$" + revStr;
    vector<int> lps = compute(cnct);
    return str.length() - lps.back();
}