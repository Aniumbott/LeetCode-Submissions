class Trie {
private:
    Trie* a[26]=  {};
    bool t = false;
public:
    Trie() {}
    
    void insert(string word) {
        Trie* node = this;
        for(auto c:word){
            c -= 'a';
            if(!node->a[c]){ node->a[c] = new Trie(); }
            node = node->a[c];
        }
        node->t = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(auto c:word){
            c-='a';
            if(!node->a[c]) return false;
            node = node->a[c];
        }
        return node->t;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto c:prefix){
            c -= 'a';
            if(!node->a[c]) return false;
            node = node->a[c];
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