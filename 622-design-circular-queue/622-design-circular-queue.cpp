class MyCircularQueue {
public:
    int n, t=0;
    ListNode *front, *back, *root;
    MyCircularQueue(int k) {
        n=k;
        root = new ListNode(-1);
        back = root;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        ListNode *tp = new ListNode(value);
        
        if(t == 0) front = tp;
        
        back->next = tp;
        back = back->next;
        // cout << value << " ";
        t++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        if(t == 1) front = back = root;
        
        else front = front->next;
        // cout << front->val << " ";
        t--;
        return true;
    }
    
    int Front() {
        return front->val;
    }
    
    int Rear() {
        return back->val;
    }
    
    bool isEmpty() {
        return (t==0)?true:false;
    }
    
    bool isFull() {
        return (t==n)?true:false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */