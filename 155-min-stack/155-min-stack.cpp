class MinStack {
    class Node{
        public:
            int value;
            int min;
            Node *next = NULL;

            Node(int x, int min){
                this->value=x;
                this->min=min;
            }
    };
    
    Node *head;
public: 
    void push(int x) {
        if(!head){
            head = new Node(x,x);
        }else{
            Node *n = new Node(x, min(x,head->min));
            n->next = head;
            head=n;
        }
    }

    void pop() {
        if(head)
            head = head->next;
    }

    int top() {
        if(head)
            return head->value;
        return -1;
    }

    int getMin() {
        if(head)
            return head->min;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */