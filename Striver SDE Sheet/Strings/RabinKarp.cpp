#include <bits/stdc++.h>
using namespace std;

int regenerateHash(string str, int oldIndex, int newIndex, int oldHash, int patternLen, int prime) {
    int newHash = oldHash - str[oldIndex];
    newHash = newHash / prime;
    newHash += str[newIndex] * pow(prime, patternLen - 1);
    return newHash;
}

int generateHash(string str, int len, int prime) {
    int hash = 0;
    for (int i = 0; i <= len; i++) {
        hash += ((str[i] - 'a') * pow(prime, i));
    }
    return hash;
}

void search(string pat, string txt, int prime) {
    int m = pat.length();
    int n = txt.length();
    int i, j;
    int patHash = generateHash(pat, m - 1, prime), txtHash = generateHash(txt, m - 1, prime);
    for (i = 0; i <= n - m; i++) {
        if (patHash == txtHash) {
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
            }
        } else if (i <= n - m) {
            txtHash = regenerateHash(txt, i, i + m - 1, txtHash, m, prime);
        }
    }
}

int main() {
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    int q = 101;
    search(pat, txt, q);
    return 0;
}