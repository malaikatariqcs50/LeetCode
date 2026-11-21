//Lat Solved on: 21 Nov, 2026, Saturday
//Last Solved in: 1 hour

class Twitter {
    int timestamp = 0;

public:
    unordered_map <int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {}

    void postTweet(int userId, int tweetId) { 
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;

        if (tweets[userId].size() > 10) {
            tweets[userId].erase(tweets[userId].begin());
        }
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<tuple<int, int, int>> pq;

        int tweetIdx = -1;
        if(!tweets[userId].empty()){
            tweetIdx = tweets[userId].size() - 1;
        }

        if(tweetIdx >= 0){
            auto [time, twId] = tweets[userId][tweetIdx];
            pq.push({time, userId, tweetIdx});
        }

        for(auto followeeId:follows[userId]){
            int twIdx = -1;
            if(!tweets[followeeId].empty()){
                twIdx = tweets[followeeId].size() - 1;
            }

            if(twIdx >= 0){
                auto [time, twId] = tweets[followeeId][twIdx];
                pq.push({time, followeeId, twIdx});
            }
        }

        if(pq.empty()){
            return feed;
        }

        while(!pq.empty() && feed.size() < 10){
            auto [time, personId, index] = pq.top();
            auto [t, tweetId] = tweets[personId][index];
            pq.pop();

            feed.push_back(tweetId);

            index--;
            if(index >= 0){
                auto[newTime, newId] = tweets[personId][index];
                pq.push({newTime, personId, index});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

//Pattern: Find the most recent tweet of user and all its followers, put in pq
//Pq gives the most recent to least recent
//If not gotten 10 posts, then get the 2nd most recent of user and all its followers