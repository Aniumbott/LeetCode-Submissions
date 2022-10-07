class MyCalendarThree {   
public:
    map<int, int> count = {{-1,0}};
    int ans = 0;
    MyCalendarThree() {
    }
    
    int book(int st, int en) {        
    auto start = count.emplace(st, (--count.upper_bound(st))->second);
    auto end = count.emplace(en, (--count.upper_bound(en))->second);
    for (auto i = start.first; i != end.first; ++i)
        ans = max(ans, ++(i->second));
    return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */