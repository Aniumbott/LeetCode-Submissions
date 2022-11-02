class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(),bank.end()};
        if(!st.count(end)) return -1;
        queue<string> q;
        q.push(start);
        int stp=0, s;
        string cur,t;
        while(!q.empty()){
            s=q.size();
            while(s--){
                cur=q.front();
                q.pop();
                if(cur==end) return stp;
                st.erase(cur);
                for(int i=0;i<8;i++){
                    t=cur;
                    t[i]='A';
                    if(st.count(t)) q.push(t);
                    t[i]='C';
                    if(st.count(t)) q.push(t);
                    t[i]='G';
                    if(st.count(t)) q.push(t);
                    t[i]='T';
                    if(st.count(t)) q.push(t);
                }
            }
            stp++;
        }
        return -1;
    }
};