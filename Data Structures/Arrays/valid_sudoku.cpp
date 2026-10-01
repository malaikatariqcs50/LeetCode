//Valid Sudoku
//Last Soved in: 20 minutes
//Last Solved on: 27 - Sept - 2026
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Rows
        for (int i = 0; i < 9; i++) {
            vector<bool> nums(10, false);
            for (int j = 0; j < 9; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Columns
        for (int i = 0; i < 9; i++) {
            vector<bool> nums(10, false);
            for (int j = 0; j < 9; j++) {
                if (!isdigit(board[j][i]))
                    continue;
                if (nums[board[j][i] - '0'] == true)
                    return false;
                nums[board[j][i] - '0'] = true;
            }
        }

        // Board 1
        vector<bool> nums(10, false);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Board 2
        nums.assign(10, false);
        for (int i = 3; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Board 3
        nums.assign(10, false);
        for (int i = 6; i < 9; i++) {
            for (int j = 0; j < 3; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Board 4
        nums.assign(10, false);
        for (int i = 0; i < 3; i++) {
            for (int j = 3; j < 6; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Board 5
        nums.assign(10, false);
        for (int i = 3; i < 6; i++) {
            for (int j = 3; j < 6; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Board 6
        nums.assign(10, false);
        for (int i = 6; i < 9; i++) {
            for (int j = 3; j < 6; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Board 7
        nums.assign(10, false);
        for (int i = 0; i < 3; i++) {
            for (int j = 6; j < 9; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Board 8
        nums.assign(10, false);
        for (int i = 3; i < 6; i++) {
            for (int j = 6; j < 9; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }

        // Board 9
        nums.assign(10, false);
        for (int i = 6; i < 9; i++) {
            for (int j = 6; j < 9; j++) {
                if (!isdigit(board[i][j]))
                    continue;
                if (nums[board[i][j] - '0'] == true)
                    return false;
                nums[board[i][j] - '0'] = true;
            }
        }
        return true;
    }
};