class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
                if(nums.size() == 0) return 0;
                        unordered_set<int> mp;
                                for(int i=0; i < nums.size(); i++){
                                            mp.insert(nums[i]);
                                                    }
                                                            int maxLen = 1;
                                                                    for(int start : mp){
                                                                        if(!mp.count(start - 1)){
                                                                                int num = start;
                                                                                        int length = 1;

                                                                                                while(mp.count(num + 1)){
                                                                                                            length++;
                                                                                                                        num++;
                                                                                                                                }

                                                                                                                                        maxLen = max(maxLen, length);
                                                                                                                                            }
                                                                                                                                            }
                                                                                                                                                    return maxLen;
                                                                                                                                                        }
                                                                                                                                                        };

                                                                                                                                                        //Pattern: Longest Consecutive Sequence 
                                                                                                                                                        //Last solved on: 27 Sept 2026
                                                                                                                                                        //Last solved in: 45 mins
                                                                                                                                                        //Clue: O(n) required + very big integer range
                                                                                                                                                        //Tool: Hash set for average O(1) lookups
                                                                                                                                                        //Trick: Only start from x when x-1 doesn't exist and walk forward i.e: x+1, x+2

                                                                                                                                                        
}