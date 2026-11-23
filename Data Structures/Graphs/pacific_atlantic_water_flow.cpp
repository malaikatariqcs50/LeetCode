//Last Solved on: 23 Nov, 2026, Monday
//Last Solved in: 45 mins

class Solution {
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
private:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        visited[i][j] = true;

        for(auto& dir:directions){
            int x = i+dir[0];
            int y = j+dir[1];

            if(x >= heights.size() || y >= heights[0].size() || x < 0 || y < 0 )
                continue;
            if(visited[x][y])
                continue;
            if(heights[x][y] < heights[i][j])
                continue;
                
            dfs(x, y, heights, visited);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        vector<vector<int>> coordinates;

        for(int j=0; j<m; j++){
            dfs(0, j, heights, pacific);
        }

        for(int i=0; i<n; i++){
            dfs(i, 0, heights, pacific);
        }

        for(int j=0; j<m; j++){
            dfs(n-1, j, heights, atlantic);
        }

        for(int i=0; i<n; i++){
            dfs(i, m-1, heights, atlantic);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    coordinates.push_back({i, j});
                }
            }
        }
        return coordinates;
    }
};