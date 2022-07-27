class LRUCache {
private:
    class Node{

    public:
    int key;
    int val;
    Node * prev;
    Node * next;

    Node (int key, int val){
    this->key=key;
    this->val=val;
    }
};

Node * head= new Node(-1,-1);
Node * tail= new Node(-1,-1);

unordered_map<int, Node*> mp;
int cache_capacity;
    
public:

void removenode(Node * currnode){
    Node * next_node=currnode->next;
    Node * prev_node=currnode->prev;
    
    next_node->prev=prev_node;
    prev_node->next=next_node;
}

void addnode(Node * currnode){
    currnode->next=head->next;
    currnode->prev=head;
    currnode->next->prev=currnode;
    head->next=currnode;
}

LRUCache(int capacity) {
    
    this->cache_capacity=capacity;
    head->next=tail;
    tail->prev=head;
}

int get(int key) {
    if(mp.find(key)==mp.end()) return -1;
    
    
    Node * currnode=mp[key];
    int result=currnode->val;
    mp.erase(key);
    removenode(currnode);
    addnode(currnode);
    mp[key]=head->next;
    return result;
}

void put(int key, int value) {
    if(mp.find(key)!=mp.end()){
        
        Node * currnode=mp[key];
        mp.erase(key);
        removenode(currnode);
    }
    
    if(mp.size()==cache_capacity){
        mp.erase(tail->prev->key);
        removenode(tail->prev);
    }
    addnode(new Node(key, value));
    mp[key]=head->next;
}
};