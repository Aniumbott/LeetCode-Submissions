class MyCircularDeque {
private:
    vector<int> buffer;
    int cnt=0;
    int k;
    int front;
    int rear=0;
public:
    MyCircularDeque(int k){
        this->buffer.resize(k,0);
        this->k = k;
        this->front = k-1;
    }
    
    bool insertFront(int value) {
        if (cnt == k) return false;
        buffer[front] = value;
        front = (front - 1 + k) % k;
        ++cnt;

        return true;
    }
    
    bool insertLast(int value) {
        if (cnt == k) return false;
        buffer[rear] = value;
        rear = (rear + 1) % k;
        ++cnt;

        return true;
    }
    
    bool deleteFront() {
        if (cnt == 0) return false;
        front = (front + 1) % k;
        --cnt;

        return true;
    }
    
    bool deleteLast() {
        if (cnt == 0) return false;
        rear = (rear - 1 + k) % k;
        --cnt;

        return true;
    }
    
    int getFront() {
        if (cnt == 0) return -1;
        return buffer[(front + 1) % k];
    }
    
    int getRear() {
        if (cnt == 0) return -1;
        return buffer[(rear - 1 + k) % k];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == k;
    }
};