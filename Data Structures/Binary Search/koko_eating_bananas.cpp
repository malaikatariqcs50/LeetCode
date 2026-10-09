//Last Solved on: 9 Oct, 2026, Friday
//Last Solved in: 1 hour
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            long long hours = 0;
            int mid = low + (high - low)/2;

            for(int i=0; i < piles.size(); i++){
                hours += (piles[i] + (long long)mid - 1)/mid; 
                
                if(hours > h){
                    break;
                }
            }

            if(hours > h){
                low = mid + 1;
            }
            else if(hours <= h){
                high = mid - 1;
            }
        }
        return low;
    }
};

//Pattern: Binary Search
//Find the range of possible answers and mid.
//Move high and left as feasible to shorten the range of answers.
//If answer found, save and search for a smaller answer