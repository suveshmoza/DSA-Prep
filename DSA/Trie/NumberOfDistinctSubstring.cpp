class Trie {
   public:
    Trie* child[26];
    bool isEnd = false;
};
Trie* root;

void solve(Trie* root, string word, int& count) {
    int n = word.length();
    for (int i = 0; i < n; i++) {
        Trie* curr = root;
        for (int j = i; j < n; j++) {
            if (curr->child[word[j] - 'a'] == NULL) {
                count++;
                curr->child[word[j] - 'a'] = new Trie();
            }
            curr = curr->child[word[j] - 'a'];
        }
    }
    return;
}

int distinctSubstring(string& word) {
    root = new Trie();
    int count = 0;
    solve(root, word, count);
    return count;
}