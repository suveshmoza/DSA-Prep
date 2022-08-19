class LRUCache {
   public:
    class Node {
       public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* temp) {
        Node* delPrev = temp->prev;
        Node* delNext = temp->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            int res = temp->val;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto existing = mp[key];
            mp.erase(key);
            deleteNode(existing);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};