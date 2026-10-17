//Last Solved on: 17 Oct, 2026, Saturday
//Last Solved in: 1 hour
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> freq;
        int windowLength = 0;
        int maxFreq = 0;
        int maxLength = 0;

        while (left <= right && right < s.length()) {
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);
            right++;
            windowLength++;

            while (windowLength - maxFreq > k) {
                freq[s[left]]--;
                windowLength--;
                left++;
            }

            maxLength = max(maxLength, windowLength);
        }
        return maxLength;
    }
};

//Pattern: Sliding Window
//Build a freq map, chose the char that appeared the most times and subtract from the total chars
//You will find the number of other chars
//If those can be changed (<=k) change them, otherwise remove from left.