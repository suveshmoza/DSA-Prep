//* Brute Force
bool search(string a, string b) {
    int m = a.size();
    int n = b.size();

    for (int i = 0; i <= m - n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (a[i + j] != b[j])
                break;
        }
        if (j == n)
            return true;
    }
    return false;
}

int repeatedStringMatch(string a, string b) {
    int count = 0;
    string temp = "";
    while (temp.length() < b.length()) {
        count++;
        temp += a;
    }
    if (search(temp, b)) {
        return count;
    }
    temp += a;
    if (search(temp, b)) {
        return count + 1;
    }
    return -1;
}

//* Using KMP
bool kmp(string text, string patt, vector<int> lps) {
    int i = 0, j = 0;
    while (i < text.length() && j < patt.length()) {
        if (text[i] == patt[j]) {
            i++, j++;
            if (j == patt.length()) return true;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
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

bool search(string a, string b) {
    vector<int> lps = compute(b);
    return kmp(a, b, lps);
}

int repeatedStringMatch(string a, string b) {
    int count = 0;
    string temp = "";
    while (temp.length() < b.length()) {
        count++;
        temp += a;
    }
    if (search(temp, b)) {
        return count;
    }
    temp += a;
    if (search(temp, b)) {
        return count + 1;
    }
    return -1;
}