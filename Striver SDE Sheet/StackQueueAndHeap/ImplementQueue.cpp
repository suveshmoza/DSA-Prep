//* Using Linked List
class Node {
   public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
   public:
    Node *head, *tail;
    Queue() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        return (head == NULL && tail == NULL);
    }

    void enqueue(int data) {
        Node* temp = new Node(data);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    int dequeue() {
        if (!head) return -1;
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        int tempData = temp->data;
        delete (temp);
        return tempData;
    }

    int front() {
        if (!head) {
            return -1;
        }
        return head->data;
    }
};

//* Using Stack

class MyQueue {
   public:
    stack<int> s1, s2;

    MyQueue() {
    }

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int popped = s1.top();
        s1.pop();
        return popped;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};
