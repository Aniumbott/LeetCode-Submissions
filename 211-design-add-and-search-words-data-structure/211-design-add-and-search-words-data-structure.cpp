class WordDictionary {
public:
    WordDictionary() {}
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(auto c: word){
            if(!node->next[c - 'a']) node->next[c - 'a'] = new WordDictionary();
            node = node->next[c - 'a'];
        }
        node->isKey = true;
    }
    
    bool search(string word) {
        return helper(word, this);
    }

private:
    bool isKey = false;
    WordDictionary* next[26] = {};
    
    bool helper(string word, WordDictionary* node){
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(c != '.'){
                if(!node->next[c - 'a']) return false;
                node = node->next[c - 'a'];
            }
            else{
                bool found = false;
                int j = 0;
                for(; j < 26; j++){
                    if(node->next[j]) found |= helper(word.substr(i + 1), node->next[j]);
                    if(found) return true;
                }
                if(j == 26) return false;
            }
        }
        return node->isKey;
    }
};