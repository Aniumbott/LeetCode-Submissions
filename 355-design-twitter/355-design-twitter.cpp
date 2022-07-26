class Twitter {
private:
    struct ListNode {
      int uid, tid;
      ListNode *next;
      ListNode(int x, int y) : uid(x), tid(y), next(NULL) {}
    };
    
    bool dp[501][501] = {false};
    
    ListNode *head;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        if(!head){
            head = new ListNode(userId, tweetId);
        }
        else{
            ListNode *tp = new ListNode(userId, tweetId);
            tp->next = head;
            head = tp;    
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        ListNode *cur = head;
        
        vector<int> ans;
        
        while((cur != NULL) && (ans.size() < 10)){
            if((userId == cur->uid) || (dp[userId][cur->uid])){
                ans.push_back(cur->tid);
            }
            cur = cur->next;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        dp[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        dp[followerId][followeeId] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */