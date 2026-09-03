class Node {
public:
    int key;
    int val;
    Node* next;

    Node(int k = -1, int v = -1, Node* n = nullptr)
        : key(k), val(v), next(n) {}
};

class MyHashMap {
    vector<Node*> map;

public:
    MyHashMap() {
        map.resize(1000);
        for(int i = 0; i < 1000; i++) {
            map[i] = new Node(); // dummy node
        }
    }
    
    void put(int key, int val) {
        int hash = key % 1000;
        Node* node = map[hash];
        while(node->next) {
            if(node->next->key == key) {
                //Update existing value
                node->next->val = val;
                return;
            }
            node = node->next;
        }
        node->next = new Node(key, val);
    }
    
    int get(int key) {
        int hash = key % 1000;
        Node* node = map[hash]->next;
        while(node) {
            if(node->key == key)
                return node->val;
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = key % 1000;
        Node* node = map[hash];
        while(node->next) {
            if(node->next->key == key) {
                Node* rem = node->next;
                node->next = rem->next;
                delete rem;
                return;
            }
            node = node->next;
        }
    }
};