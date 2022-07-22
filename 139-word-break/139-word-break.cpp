class Solution {
private:
    //----------------------------------------------------------------
    class Trie{
      public:
        Trie *child[26];
        bool isEnd = false;
    };
    
    void insert(string &word, Trie* root){
        Trie *cur = root;
        for(auto &ch : word){
            if(!cur->child[ch-'a']) cur->child[ch-'a'] = new Trie();
            cur=cur->child[ch-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string &word, Trie* root){
        Trie *cur = root;
        for(auto &ch : word){
            if(!cur->child[ch-'a']) return false;
            cur=cur->child[ch-'a'];
        }
        return cur->isEnd;
    }
    
    //----------------------------------------------------------------
    
    int dp[300][300], n;
    string s;
    
    bool helper(int st, Trie* node){
        if(st == n) return true;
        
        if(dp[st][n]!=-1) return dp[st][n];
        
        for(int i=st; i<n; i++){
            string str = s.substr(st, i-st+1);
            if(search(str, node)){
                if(helper(i+1, node)) return dp[st][i] = 1;
            }
        }
        return dp[st][n] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root = new Trie();
        memset(dp, -1, sizeof(dp));
        this->s = s;
        this->n = s.size();
        
        for(auto&s:wordDict) insert(s,root);

        return helper(0, root);
    }
};