//* Approach 1
//* TC: O(1) SC: O(N)
#define pii pair<int, int>

class MinStack {
   public:
    stack<pii> s;
    MinStack() {
        while (!s.empty()) {
            s.pop();
        }
    }

    void push(int val) {
        if (s.empty())
            s.push({val, val});
        else
            s.push({val, min(val, s.top().second)});
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

//* Approach 2
//* TC: O(1) SC: O(1)
class MinStack {
   public:
    stack<long long> st;
    long long mini;
    MinStack() {
        while (!st.empty()) {
            st.pop();
        }
        mini = INT_MAX;
    }

    void push(int val) {
        if (st.size() == 0) {
            st.push(val);
            mini = val;
        } else if (val >= mini) {
            st.push(val);
        } else {
            long long data = 2 * (long long)val - mini;
            st.push(data);
            mini = val;
        }
    }

    void pop() {
        if (st.size() == 0) {
            return;
        } else {
            if (st.top() >= mini) {
                st.pop();
            } else {
                mini = 2 * mini - st.top();
                st.pop();
            }
        }
    }

    int top() {
        if (st.size() == 0) {
            return -1;
        } else {
            if (st.top() >= mini) {
                return st.top();
            } else {
                return mini;
            }
        }
    }

    int getMin() {
        if (st.size() == 0) {
            return -1;
        }
        return mini;
    }
};