struct DLinkNode {
    int key;
    int value;
    DLinkNode* prev;
    DLinkNode* next;
    DLinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> size = 0;
    }
    
    int get(int key) {
        if (index.find(key) != index.end()) {
            DLinkNode *node = index[key];
            remove(node);
            insert(node);
            return node -> value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (index.find(key) != index.end()) {
            DLinkNode *node = index[key];
            remove(node);
            insert(node);
            node -> value = value;
        } else {
            DLinkNode *node = new DLinkNode(key, value);
            insert(node);
            index[key] = node;
            if (size == capacity) {
                index.erase(tail -> key);
                remove(tail);
            } else {
                ++size;
            }
        }
    }

private:
    int capacity;
    int size;
    unordered_map<int, DLinkNode*> index;
    DLinkNode *head = nullptr;
    DLinkNode *tail = nullptr;

    void insert(DLinkNode *node) {
        if (node == nullptr) {
            return;
        }
        if (head == nullptr) {
            head = tail = node;
            return;
        }
        node -> next = head;
        head -> prev = node;
        head = node;
    }

    void remove(DLinkNode *node) {
        if (node == nullptr || head == nullptr) {
            return;
        }
        if (head == tail) {
            if (node == head) {
                head = tail = nullptr;
            }
            return;
        }

        if (node == head) {
            head = head -> next;
            node -> next = nullptr;
            head -> prev = nullptr;
        } else if (node == tail) {
            tail = tail -> prev;
            node -> prev = nullptr;
            tail -> next = nullptr;
        } else {
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
            node -> prev = nullptr;
            node -> next = nullptr;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */