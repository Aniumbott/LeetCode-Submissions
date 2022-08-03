class MyCalendar {
private:
    class item{
        public:
            int start, end;
            item *left = NULL;
            item *right = NULL;
            item(int start, int end){
                this->start = start;
                this->end = end;
            }
    };
    
    item *head;
public:
    MyCalendar() {
        head = new item(0, 0);
    }
    
    
    bool insert(item *root, int start, int end){
        if(!root) return false;
        if(root->start >= end && root->start > start){
            if(root->left) return insert(root->left, start, end);  
            else{
                root->left = new item(start, end);
                return true;
            }
        } 
        if(root->end < end && root->end <= start){
            if(root->right) return insert(root->right, start, end);  
            else{
                root->right = new item(start, end);
                return true;
            }
        } 
        return false;
    }
    
    bool book(int start, int end) {
        item *cur = head;
        if(cur->start == 0 && cur->end == 0){
            cur->start = start;
            cur->end = end;
            return true;
        }
        else return insert(cur, start, end);
    }
};