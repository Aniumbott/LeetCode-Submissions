class MyCircularQueue {
public:
    vector<int> v;
    int n, front, back, t=0;
    
    MyCircularQueue(int k) {
        n=k;
        v.assign(k, -1);
        front = 0;
        back = -1;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            back = (back+1)%n;
            v[back] = value;
            t++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            v[front] = -1;
            front = (front + 1)%n;
            t--;
            return true;
        }
        return false;
    }
    
    int Front() {
        return isEmpty()?-1:v[front];
    }
    
    int Rear() {
        return isEmpty()?-1:v[back];
    }
    
    bool isEmpty() {
        return t == 0;
    }
    
    bool isFull() {
        return t == n;
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