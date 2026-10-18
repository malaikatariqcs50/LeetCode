//Last Solved on: 18 Oct, 2026, Sunday
//Last Solved in: 1 hour
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        vector<int> freq(128, 0);

        for (int i = 0; i < t.length(); i++) {
            freq[t[i]]++;
        }

        int minLength = INT_MAX;
        int start = 0;
        int left = 0;
        int required = t.size();
        deque<int> v;

        for(int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0) {
                required--;
            }
            freq[s[right]]--;

            while (required == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]] > 0){
                    required++;
                }
                left++;
            }
        }
        if (minLength == INT_MAX) {
            return "";
        }
        return s.substr(start, minLength);
    }
};

//Pattern: Sliding Window
//Left and right indicate a valid window, if a window is invalid, move right, if it is valid, move left (when becomes invalid, so move right again)
//required = 0: valid; required > 0: invalid; required starts from t.size()
//Decrease the freq when going from right
//Increase the freq When going from left
//If freq of right char > 0 (char needed); required--;
//If freq of  left char > 0 (window is invalid again, char is needed from the right); required++;