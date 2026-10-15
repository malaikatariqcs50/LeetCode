//Last Solved on: 15 Oct, 2026, Thursday
//Last Solved in: 15 mins
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum = 0;

        int left = 0;
        int right = 1;

        while(right < prices.size()){
            maximum = max(maximum, prices[right]-prices[left]);
            if(prices[left] > prices[right]){
                left = right;
            }
            else
                right++;
        }
        return maximum;
    }
};

//Pattern: sliding window
//Find the max profit by increasing the window from a min value
//If found a new min, restart the window from there