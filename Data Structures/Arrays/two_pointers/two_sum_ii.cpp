class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
                int left = 0;
                        int right = numbers.size()-1;
                                while(left < right){
                                            int sum = numbers[left] + numbers[right];
                                                        
                                                                    if(sum == target){
                                                                                    return {left+1, right+1};
                                                                                                }
                                                                                                            if(sum > target){
                                                                                                                            right--;
                                                                                                                                        }
                                                                                                                                                    else {
                                                                                                                                                                    left++;
                                                                                                                                                                                }
                                                                                                                                                                                        }
                                                                                                                                                                                                return {};
                                                                                                                                                                                                    }
                                                                                                                                                                                                    };

                                                                                                                                                                                                    //Last solved on: 27 Sept 2026
                                                                                                                                                                                                    //Last Solved in: 25 mins
                                                                                                                                                                                                    //Sorted array + pair/target → two pointers (L=0, R=n-1). If sum > target, R--; if sum < target, L++.
                                                                                                                                                                                                    //O(n) time, O(1) space.
}