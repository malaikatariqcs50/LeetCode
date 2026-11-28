//Last Solved on: 28 Nov, 2026, Saturday
//Last Solved in: 30 minutes
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        int min_cost = 0;
        minDist[0] = 0;
        for(int i=0; i < n; i++){
            int u=-1;
            
            for(int j = 0; j < n; j++){
                if(!visited[j] && (
                u == -1 || minDist[j] < minDist[u]
                )){
                    u = j;
                }
            }
            
            visited[u] = true;
            min_cost += minDist[u];
            
            for(int v = 0; v<n; v++){
                if(visited[v]){
                    continue;
                }
                
                int dist = abs(points[v][0] - points[u][0]) + abs(points[v][1] - points[u][1]);
                
                minDist[v] = min(minDist[v], dist);
            }
        }
        return min_cost;
    }
};

//Prim's Algo:
//Start with a node/vertex (0) and compare it's distance with all other nodes
//Add that node in the tree (visited[node] = true) and calculate the total cost of the tree
//Then compare the cost of the tree to all other nodes that are not in the tree (visited[node] == false)
//Keep moving from one node with the minimum distance to the other nodes with the next min dist.
//No cycles, only min cost