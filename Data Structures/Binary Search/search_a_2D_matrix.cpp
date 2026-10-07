//Last Solved on: 7 Oct, 2026
//Last Solved in: 1 hr
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() * matrix[0].size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;

            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();

            if(target == matrix[row][col]){
                return true;
            }

            if(target < matrix[row][col]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};

//Pattern:
//2D -> 1D Flattened: know the index(mid) in 1D, find two in 2D by:
//row = index / cols;
//col = index % cols;
//1D -> 2D => index = row * cols + col;