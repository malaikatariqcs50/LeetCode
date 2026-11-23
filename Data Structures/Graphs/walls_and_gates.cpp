//Last Solved on: 22 Nov, 2026, Sunday
//Last Solved in: 30 minutes

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [i, j] = q.front();
                q.pop();

                if(i+1 < n && grid[i+1][j] != -1){
                    if(grid[i][j] + 1 < grid[i+1][j]){
                        grid[i+1][j] = grid[i][j]+1;
                        q.push({i+1, j});
                    }
                }

                if(j+1 < m && grid[i][j+1] != -1){
                    if(grid[i][j] + 1 < grid[i][j+1]){
                        grid[i][j+1] = grid[i][j]+1;
                        q.push({i, j+1});
                    };
                }

                if(i-1 >= 0 && grid[i-1][j] != -1){
                    if(grid[i][j] + 1 < grid[i-1][j]){
                        grid[i-1][j] = grid[i][j]+1;
                        q.push({i-1, j});
                    }
                }

                if(j-1 >= 0 && grid[i][j-1] != -1){
                    if(grid[i][j] + 1 < grid[i][j-1]){
                        grid[i][j-1] = grid[i][j]+1;
                        q.push({i, j-1});
                    }
                }
            }
        }
    }
};
