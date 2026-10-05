struct Post {
    int userId;
    int tweetId;
    unsigned int time;
};

struct PostCompare{
    bool operator()(const Post& p1, const Post& p2) const {
        return p1.time < p2.time;
    }
};

class Twitter {
public:
    Twitter() {
        curr_time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        while (user_posts[userId].size() >= 10) user_posts[userId].pop_front();
        user_posts[userId].push_back({userId, tweetId, curr_time});
        ++curr_time;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Post, vector<Post>, PostCompare> pq;
        for (int user : following[userId]) {
            if (user_posts.contains(user)) {
                for (Post p : user_posts[user]) {
                    pq.push(p);
                }
            }
        }
        if (user_posts.contains(userId)) {
            for (Post p : user_posts[userId]) {
                    pq.push(p);
            }
        }
        vector<int> feed;
        for (int i = 0; i < 10; ++i) {
            if (pq.empty()) break;
            Post p = pq.top();
            pq.pop();
            feed.push_back(p.tweetId);
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        
    }

private:
    unordered_map<int, deque<Post>> user_posts; 
    unordered_map<int, unordered_set<int>> following;
    unsigned int curr_time;
};
