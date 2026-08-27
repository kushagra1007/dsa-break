class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

private:
    Node* head;
    Node* tail;

    unordered_map<int, Node*> m;
    int capacity;
    
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void delNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(Node* node) {
        delNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* node = m[key];

        moveToFront(node);

        return node->val;
    }

    void put(int key, int value) {

        if (m.find(key) != m.end()) {

            Node* node = m[key];

            node->val = value;

            moveToFront(node);

            return;
        }

        if (m.size() == capacity) {

            Node* lru = tail->prev;

            m.erase(lru->key);

            delNode(lru);

            delete lru;
        }

        Node* node = new Node(key, value);

        addNode(node);

        m[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */