class MyHashMap {
private:
    static const int SIZE = 1009;  
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v, Node* n = nullptr) {
            key = k;
            value = v;
            next = n;
        }
    };

    Node* table[SIZE] = {};
    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        
    }

    void put(int key, int value) {
        int index = hash(key);
        Node* curr = table[index];

        while (curr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        table[index] = new Node(key, value, table[index]);
    }

    int get(int key) {
        int index = hash(key);

        Node* curr = table[index];

        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }

        return -1;
    }

    void remove(int key) {
        int index = hash(key);

        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {

                if (prev == nullptr) {
                    table[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */