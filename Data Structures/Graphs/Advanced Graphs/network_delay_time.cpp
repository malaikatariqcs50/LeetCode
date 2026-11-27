//Last Solved on: 27 Nov, 2026, Friday
//Last Solved in: 30 minutes

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto& t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;

        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();

            if(dist > distance[node]){
                continue;
            }

            for(auto& it:adj[node]){
                int adjNode = it.first;
                int adjNodeDis = it.second;

                if(dist + adjNodeDis < distance[adjNode]){
                    distance[adjNode] = dist + adjNodeDis;
                    pq.push({adjNodeDis, adjNode});
                }
            }
        }

        int ans = 0;

        for(int i=1; i <= n; i++){
            if(distance[i] == INT_MAX){
                return -1;
            }

            ans = max(ans, distance[i]);
        }
        return ans;
    }
};

//Pattern: Save the distance from the source to a node in a priority queue
//It will give you the shortest distance from source to a certain node first
//Process that node first to find the shortest path