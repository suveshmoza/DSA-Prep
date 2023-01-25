class Solution {
   public:
    class Trie {
       public:
        Trie* child[2];
    };
    Trie* root;

    void insert(int num) {
        Trie* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->child[bit] == NULL) {
                curr->child[bit] = new Trie();
            }
            curr = curr->child[bit];
        }
    }

    int search(int num) {
        Trie* curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->child[1 - bit] != NULL) {
                ans = ans | 1 << i;
                curr = curr->child[1 - bit];
            } else {
                curr = curr->child[bit];
            }
        }
        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        vector<pair<int, pair<int, int>>> offlineQueries;
        sort(nums.begin(), nums.end());
        int index = 0;
        for (auto& it : queries) {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        int ind = 0;
        root = new Trie();
        for (int i = 0; i < offlineQueries.size(); i++) {
            int xi = offlineQueries[i].second.first;
            int mi = offlineQueries[i].first;
            int idx = offlineQueries[i].second.second;
            while (ind < nums.size() && nums[ind] <= mi) {
                insert(nums[ind]);
                ind++;
            }
            if (ind == 0) {
                ans[idx] = -1;
            } else {
                ans[idx] = search(xi);
            }
        }

        return ans;
    }
};