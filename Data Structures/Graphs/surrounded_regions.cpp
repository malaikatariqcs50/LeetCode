//Last Solved on: 23 Nov, 2026, Monday
//Last Solved in: 25 mins

class Solution {
vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;

private:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if(board[i][j] == 'X' || visited[i][j])
            return;

        visited[i][j] = true;

        for(auto& dir:directions){
            int x = i + dir[0];
            int y = j + dir[1];

            if(x < 0 || y < 0 || x >= n || y >= m)
                continue;
            if(board[x][y] == 'X' || visited[x][y]){
                continue;
            }

            dfs(x, y, board, visited);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int j=0; j<m; j++){
            dfs(0, j, board, visited);
            dfs(n-1, j, board, visited);
        }

        for(int i=0; i<n; i++){
            dfs(i, 0, board, visited);
            dfs(i, m-1, board, visited);
        }

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(board[i][j] == 'O' && visited[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};