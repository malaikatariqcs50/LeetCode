//Last Solved on: 30 Sept 2026
//Last solved in: 45 mins
class Solution {
public:
    int trap(vector<int>& height) {
        int units = 0;
        int left = 0;
        int right = 0;
        for(int i=0; i<height.size(); i++){
            if(height[i] >= height[right]){
                right = i;
            }
        }
        int subtractor = height[left];
        while(left < right){
            if(height[left] > subtractor){
                subtractor = height[left];
            }
            else{
                units += subtractor - height[left]; 
            }
            left++;
        }
        right = height.size()-1; 
        subtractor = height[right];
        while(left < right){
            if(height[right] > subtractor){
                subtractor = height[right];
            }
            else{
                units += subtractor - height[right];
            }
            right--;
        }
        return units;
    }
};

//Trick: (Two pointers)
//Find the global max, scan both sides.
//Subtract current height from min