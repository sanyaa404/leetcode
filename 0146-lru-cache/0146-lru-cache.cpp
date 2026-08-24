struct DLListNode {
    int val;
    DLListNode *next;
    DLListNode *prev;
    DLListNode() : val(0), next(nullptr), prev(nullptr) {}
    DLListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    DLListNode(int x, DLListNode *next, DLListNode *prev) : val(x), next(next), prev(prev) {}
};
class LRUCache {
public:
    int capacity;

    DLListNode* head;
    DLListNode* tail;

    unordered_map<int, pair<DLListNode*, int>> mp;

    LRUCache(int n) {
        capacity = n;
        head = new DLListNode();
        tail = new DLListNode();
        head->next = tail;
        tail->prev = head;
    }

    void remove(DLListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void putlast(DLListNode* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        DLListNode* node = mp[key].first;
        int value = mp[key].second;
        remove(node);
        putlast(node);
        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            DLListNode* node = mp[key].first;
            mp[key].second = value;
            remove(node);
            putlast(node);
            return;
        }

        // Cache full → remove LRU
        if (mp.size() == capacity) {
            DLListNode* node = head->next;
            remove(node);
            mp.erase(node->val);
            delete node;
        }

        DLListNode* node = new DLListNode(key);
        putlast(node);
        mp[key] = {node, value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */