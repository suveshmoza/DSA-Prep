//* Using Two Queue

class MyStack {
   public:
    queue<int> q1, q2;

    MyStack() {
    }

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int popped = q1.front();
        q1.pop();
        return popped;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

//* Using Single Queue

class MyStack {
   public:
    queue<int> q1;

    MyStack() {
    }

    void push(int x) {
        int size = q1.size();
        q1.push(x);
        for (int i = 0; i < size; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop() {
        int popped = q1.front();
        q1.pop();
        return popped;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
