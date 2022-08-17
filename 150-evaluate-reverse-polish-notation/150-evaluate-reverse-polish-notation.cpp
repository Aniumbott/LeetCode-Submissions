/*
Its just like the Postfix Expression
*/

class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            int a, b;
            if(s[i] == "*" || s[i] == "+" || s[i] == "-" || s[i] == "/"){
                a = st.top(); 
                st.pop();
                b = st.top();
                st.pop();
                if(s[i] == "*") st.push(b*a);
                
                else if(s[i] == "+") st.push(b+a);
                
                else if(s[i] == "-") st.push(b-a);
                
                else if(s[i] == "/") st.push(b/a);
            }
            else{
                    int x = stoi(s[i]);
                    st.push(x);
            }
        }
        return st.top();   
    }
};