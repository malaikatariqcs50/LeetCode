//Last Solved on: 9 Oct, 2026, Friday
//Last Solved in: 12 minutes
class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] > nums[high]){
                low = mid+1;
            }

            else{
                high = mid - 1;
            }
        }
        return nums[low];
    }
};

//Pattern: Binary Search
//If left is sorted, min is nums[low] and check on the right
//If right is roted, minimum is nums[mid] and check on the left