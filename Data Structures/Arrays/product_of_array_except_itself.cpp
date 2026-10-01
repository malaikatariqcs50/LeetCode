//Product of array except self
//No extra space -> O(1)
//Time must be O(n), was exactly O(n) + O(n)
//Last Soved in: 6 minutes
//Last Solved on: 27 - Sept - 2026

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        vector<int> output(nums.size());

        //Add the prefixes in the output
        for(int i=0; i<nums.size(); i++){
            output[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        //Multiply postfix with the array of prefixes
        for(int i=nums.size()-1; i>=0; i--){
            output[i] *= postfix;
            postfix *= nums[i];
        }

        return output;
    }
};

//Trigger:
//Since the division wasn't allowed, had to solve using prefixes and postfixes

//Technique:
//Use the prefixes and postfixes and store them in same array as the output

//Why:
//It works because the space and time complexity are exactly as described and multiplication with prefixes and postfixes of a number guarantees the product of the whole array except itself.
