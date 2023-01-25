int kmp(string text, string patt, vector<int> lps) {
    int i = 0, j = 0;
    while (i < text.length() && j < patt.length()) {
        if (text[i] == patt[j]) {
            i++, j++;
            if (j == patt.length()) return i - patt.length();
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

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

int strStr(string haystack, string needle) {
    if (needle.length() == 0) return 0;
    vector<int> lps = compute(needle);
    return kmp(haystack, needle, lps);
}