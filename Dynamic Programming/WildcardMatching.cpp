// Recursion
class Solution {
   public:
    bool isAllStars(string s, int i) {
        for (int j = 0; j <= i; j++) {
            if (s[j] != '*') {
                return false;
            }
        }
        return true;
    }

    bool solve(string s1, string s2, int n, int m) {
        if (n < 0 && m < 0) return true;
        if (n < 0 && m >= 0) return false;
        if (n >= 0 && m < 0) {
            return isAllStars(s1, n);
        }
        if (s1[n] == s2[m] || s1[n] == '?') {
            return solve(s1, s2, n - 1, m - 1);
        } else {
            if (s1[n] == '*') {
                return solve(s1, s2, n - 1, m) || solve(s1, s2, n, m - 1);
            } else
                return false;
        }
    }

    bool isMatch(string s, string p) {
        return solve(p, s, p.length() - 1, s.length() - 1);
    }
};

// Memo
