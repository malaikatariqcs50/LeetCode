//Last Solved on: 22 Nov, 2026, Sunday
//Last Solved in: 45 mins

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int mins = 0;

        while(!q.empty() && fresh > 0){
            int size = q.size();

            while(size--){
                auto [i, j] = q.front();
                q.pop();

                if(i+1 < n && grid[i+1][j] == 1){
                    q.push({i+1, j});
                    fresh--;
                    grid[i+1][j] = 2;
                }

                if(j+1 < m && grid[i][j+1] == 1){
                    q.push({i, j+1});
                    fresh--;
                    grid[i][j+1] = 2;
                }

                if(i-1 >= 0 && grid[i-1][j] == 1){
                    q.push({i-1, j});
                    fresh--;
                    grid[i-1][j] = 2;
                }

                if(j-1 >= 0 && grid[i][j-1] == 1){
                    q.push({i, j-1});
                    fresh--;
                    grid[i][j-1] = 2;
                }
            }
            mins++;
        }
        if(fresh == 0){
            return mins;
        }

        return -1;
    }
};

//Pattern: BFS
//Check all the nodes that can be rotted, then add a minute
//Every node that is rotted, add it in the queue
//Use two loops: One that handles one minute iteration, the inside makes the fresh oranges rotten. When all are rotten on the inside loop, one iteration ends and a minute increases.