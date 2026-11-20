//Last Solved on: 20 Nov, 2026, Friday
//Last Solved in: 15 minutes

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for(int i=0; i < points.size(); i++){
            int dist = points[i][0]*points[i][0] + points[i][1] * points[i][1];
            pq.push({dist, {points[i][0], points[i][1]}});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> v(pq.size(), vector<int>(2));
        for(int i=0; i<v.size(); i++){
            v[i][0] = (pq.top().second.first);
            v[i][1] = (pq.top().second.second);
            pq.pop();
        }
        return v;
    }
};

//Priority queue