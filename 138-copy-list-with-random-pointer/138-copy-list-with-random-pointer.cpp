/*
Say we have a linked list a b c d e f
We are modifying it to a a' b b' c c' d d' e e' f f' (where a' denotes the copy of a)
Then we are setting the random nodes to the copied nodes according to the original one.
Then saparating both lists.
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* nhead = head;
        Node* rt;
        while(head){
            Node* buffer = new Node(0);
            if(head == nhead) rt = buffer;
            buffer->val = head->val;
            buffer->next = head->next;
            head->next = buffer;
            head = head->next->next;
        }
        head = nhead;
        while(head){
            if(head->random)
                head->next->random = head->random->next;
            head = head->next->next;
        }
        head = nhead;
        while(head){
            Node* buffer = head->next;
            if(head->next)
            head->next = head->next->next;
            if(buffer->next)
                buffer->next = buffer->next->next;
            head = head->next;
        }
        return rt;
    }
};