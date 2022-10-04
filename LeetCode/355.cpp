class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        stars[userId].insert(userId);
        tweets[userId].push_back({cnt++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        for(auto followee: stars[userId]) {
            for(int i = tweets[followee].size()-1; i >= 0; --i) {
                if(q.size() == 10 && q.top().first > tweets[followee][i].first) break;
                q.push(tweets[followee][i]);
                if(q.size() > 10) {
                    q.pop();
                }
            }
        }
        while(q.size() > 0) {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        stars[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            stars[followerId].erase(followeeId);
        }
    }
    
private:
    int cnt;
    unordered_map<int, unordered_set<int>> stars;
    unordered_map<int, vector<pair<int, int>>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */