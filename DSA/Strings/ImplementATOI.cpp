int myAtoi(string s) {
    int n = s.size();
    int sign = 1, i = 0;
    long long int num = 0;
    // check for negatives
    if (s[0] == '+' || s[0] == '-') {
        sign = sign == '-' ? -1 : 1;
        i++;
    }
    // ignore whitespaces
    while (s[i] == ' ' && i < n) {
        i++;
    }
    // only process numbers
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + s[i] - '0';
        // clam if out of range
        if (num > INT_MAX || num < INT_MIN) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        i++;
    }
    return num * sign;
}