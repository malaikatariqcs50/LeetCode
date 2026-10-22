//Last Solved in: 30 mins
//Last Solved on: 22 Oct, 2026, Thursday

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//Pattern: Find the meeting point of slow and fast
//Then make slow go to the beginning, make them both move one step this time
//They will meet at the cycle/duplicate
//Since each value can be represented as a valid index in the array -> Linked List