//Last Solved on: 28 Sept 2026
//Last Solved in: 15 minutes
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maximum = 0;
        while(left < right){
            int coordinates = (right - left) * min(height[left], height[right]);
            maximum = max(coordinates, maximum);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maximum;
    }
};

//Trigger:
//Find max, O(n) -> Two Pointers
//Widest area needed -> two pointers at both ends
//Move the shorter height pointer
//Widest length needed -> right - left (indices)