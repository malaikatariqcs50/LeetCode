//Last Solved on: 23 Nov, 2026, Monday
//Last Solved in: 5 mins

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
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

        vector<int> completed;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completed.push_back(course);

            for (auto next : adj[course]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if(completed.size() != n){
            return {};
        }

        return completed;
    }
};