//Last Solved on: 15 Oct, 2026, Thursday
//Last Solved in: 40 mins
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int maxLength = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            if(mp.count(s[i]) && mp[s[i]] >= start){
                start = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            maxLength = max(maxLength, i-start+1);
        }
        return maxLength;
    }
};

//Pattern: Sliding Window + hashmap
//current index - start is the length
//start changes when a duplicate is found (prev length is saved if big)
//Move start to where the duplicate was found (to keep track, hashmap is needed)