class StockSpanner {
public:
    int i=0;
    stack<int> st;
    vector<int> v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        while(!st.empty() && price >= v[st.top()] )
            st.pop();
    
        int a =st.empty()?-1:st.top();
        st.push(i);
        cout << st.top();
        i++;
        return i-a-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */