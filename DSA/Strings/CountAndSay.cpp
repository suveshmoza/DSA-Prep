string countAndSay(int n) {
    string op = "1";
    if (n == 1) return op;
    n--;
    while (n != 0) {
        string curr = "";
        for (int i = 0; i < op.size(); i++) {
            int count = 1;
            while (i + 1 < op.size() && op[i] == op[i + 1]) {
                count++;
                i++;
            }
            curr += to_string(count) + op[i];
        }
        op = curr;
        n--;
    }
    return op;
}