///* Using NGE
class StockSpanner {
   public:
    stack<int> st;
    vector<int> prices;
    int i = 0;
    StockSpanner() {
    }

    int next(int price) {
        prices.push_back(price);
        while (!st.empty() && price >= prices[st.top()]) {
            st.pop();
        }
        int res = st.empty() ? (i + 1) : (i - st.top());
        st.push(i++);
        return res;
    }
};

//* Optimized

class StockSpanner {
   public:
    stack<pair<int, int>> st;
    StockSpanner() {
    }

    int next(int price) {
        int currStreak = 1;
        while (!st.empty() && price >= st.top().first) {
            currStreak += st.top().second;
            st.pop();
        }
        st.push({price, currStreak});
        return currStreak;
    }
};