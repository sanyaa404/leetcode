class DListNode{
public:
    int val;
    DListNode* next;
    DListNode* prev;
    DListNode(): val(0), next(nullptr), prev(nullptr) {}
    DListNode(int val): val(val), next(nullptr), prev(nullptr) {}
    DListNode(int x, DListNode *next, DListNode *prev) : val(x), next(next), prev(prev) {}
};

class LRUCache {
public:
    int n;
    unordered_map<int, pair<DListNode*, int>> mp;
    DListNode* head;
    DListNode* tail;
    LRUCache(int capacity) {
        head = new DListNode();
        tail = new DListNode();
        n = capacity;
        head->next = tail; tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        detach(mp[key].first);
        putLast(mp[key].first);
        return mp[key].second;
    }

    void detach(DListNode* node){
        DListNode* prev = node->prev; DListNode* next = node->next;
        node->prev = NULL; node->next = NULL;
        next->prev = prev;
        prev->next = next;
    }

    void putLast(DListNode* node){
        DListNode* prev = tail->prev;
        prev->next = node; node->prev = prev;
        node->next = tail; tail->prev = node;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            detach(mp[key].first);
            putLast(mp[key].first);
            mp[key].second = value;
            return;
        }

        DListNode* newnode = new DListNode(key);
        mp[key] = {newnode, value};
        putLast(newnode);
        if(n > 0){
            n--;
        }else{
            int keyToRemove = head->next->val;
            DListNode* nodeToRemove = head->next;
            detach(nodeToRemove);
            mp.erase(keyToRemove);
            delete nodeToRemove;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */