class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> s1, t1;
        for(int i=0; i<s.size(); i++){
            if(s[i] != '#')
                s1.push(s[i]);
            else
                if(s1.size())
                    s1.pop();
        }
        for(int i=0; i<t.size(); i++){
            if(t[i] != '#')
                t1.push(t[i]);
            else
                if(t1.size())
                    t1.pop();
        }
        while(s1.size() && t1.size()){
            if(s1.top() != t1.top())
                return false;
            s1.pop();
            t1.pop();
        }
        if(s1.size() || t1.size())
            return false;
        return true;
    }
};