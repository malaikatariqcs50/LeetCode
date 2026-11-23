//Last Solved on: 23 Nov, 2026, Monday
//Last Solved in: 1 hour

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int completed = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            completed++;

            for(auto next : adj[course]){
                indegree[next]--;

                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        return completed == n;
    }
};

//Pattern: BFS
//Take any courses that dont depend on others and traverse those
//If any courses depend on them, make them true (degree--)
//If their degree is 0, push them in the queue and traverse them to find any courses that depend on them