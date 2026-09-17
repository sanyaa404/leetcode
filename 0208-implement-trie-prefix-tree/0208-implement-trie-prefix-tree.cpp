struct TrieNode{
    TrieNode* links[26];
    bool isEnd = false;
};

class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(!curr->links[ch-'a']){
                curr->links[ch-'a'] = new TrieNode();
            }
            curr = curr->links[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(!curr->links[ch-'a']){
                return false;
            }
            curr = curr->links[ch-'a'];
        }
        return (curr->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(!curr->links[ch-'a']){
                return false;
            }
            curr = curr->links[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */