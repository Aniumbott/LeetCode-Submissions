class LockingTree {
private:
    int n;
    vector<int> isLocked, p;
    unordered_map<int,vector<int>> c;
public:
    LockingTree(vector<int>& parent) {
        n = parent.size();
        p = parent;
        isLocked.resize(n,0);
        for(int i=0; i<parent.size(); i++)
            c[parent[i]].push_back(i);
    }
    
    bool lock(int num, int user) {
        if(!isLocked[num]){
            isLocked[num] = user;    
            return true;
        } 
        return false;
    }
    
    bool unlock(int num, int user) {
        if(isLocked[num] != user) return false;
        isLocked[num] = 0;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(isLocked[num]) return false;
        if(!checkDes(num) || !checkAns(num)) return false;
        unlockDes(num);
        isLocked[num]=user;
        return true;
    }
    
    bool checkDes(int num){
        if(isLocked[num]) return true;
        for(auto ch : c[num]){
            if(checkDes(ch)) return true;
        }
        return false;
    }
    
    void unlockDes(int num){
        isLocked[num] = 0;
        for(auto ch : c[num]) unlockDes(ch);
    }
    
    bool checkAns(int num){
        int tp = p[num];
        while(tp != -1){
            if(isLocked[tp]) return false;
            tp = p[tp];
        }
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */