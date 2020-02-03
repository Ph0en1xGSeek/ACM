class DListNode {
public:
    unordered_set<string> key_set;
    DListNode *pre;
    DListNode *next;
};

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->pre = head;
        valuemap[0] = head;
    }
    
    DListNode* addNode(int pre_value, int value) {
        int dir = value - pre_value;
        DListNode *cur = new DListNode();
        DListNode *ori = valuemap[pre_value];
        if(dir == 1) {
            cur->next = ori->next;
            cur->pre = ori;
            ori->next = cur;
            cur->next->pre = cur;
        }else if(dir == -1) {
            cur->next = ori;
            cur->pre = ori->pre;
            ori->pre = cur;
            cur->pre->next = cur;
        }
        return cur;
    }
    
    void removeNode(int value) {
        if((valuemap[value]->key_set).empty()) {
            DListNode *cur = valuemap[value];
            DListNode *pre = cur->pre;
            DListNode *nex = cur->next;
            pre->next = nex;
            nex->pre = pre;
            delete cur;
            valuemap[value] = nullptr;
        }
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int pre_value = keymap[key];
        ++keymap[key];
        int cur_value = pre_value + 1;
        if(valuemap.find(cur_value) == valuemap.end() || valuemap[cur_value] == nullptr) {
            valuemap[cur_value] = addNode(pre_value, cur_value);
        }
        (valuemap[cur_value]->key_set).insert(key);
        if(pre_value > 0) {
            (valuemap[pre_value]->key_set).erase((valuemap[pre_value]->key_set).find(key));
            removeNode(pre_value);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        int pre_value = keymap[key];
        if(pre_value > 0) {
            --keymap[key];
            int cur_value = pre_value - 1;
            if(cur_value > 0) {
                if(valuemap.find(cur_value) == valuemap.end() || valuemap[cur_value] == nullptr) {
                    valuemap[cur_value] = addNode(pre_value, cur_value);
                }
                (valuemap[cur_value]->key_set).insert(key);
            }
            (valuemap[pre_value]->key_set).erase((valuemap[pre_value]->key_set).find(key));
            removeNode(pre_value);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(tail->pre == head) {
            return "";
        }else {
            auto iter = (tail->pre->key_set).begin();
            return *iter;
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(head->next == tail) {
            return "";
        }else {
            auto iter = (head->next->key_set).begin();
            return *iter;
        }
    }
    
    ~AllOne() {
        DListNode *tmp = head;
        DListNode *nex = tmp->next;
        while(nex != tail) {
            tmp = nex;
            nex = tmp->next;
            delete tmp;
        }
        delete head;
        delete tail;
    }
private:
    unordered_map<string, int> keymap;
    unordered_map<int, DListNode*> valuemap;
    DListNode *head;
    DListNode *tail;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */