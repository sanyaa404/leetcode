class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        unordered_set<Node*> ancestors;
        while(p) {
            ancestors.insert(p);
            p = p->parent;
        }
        while(q) {
            if(ancestors.count(q))
                return q;

            q = q->parent;
        }
        return nullptr;
    }
};