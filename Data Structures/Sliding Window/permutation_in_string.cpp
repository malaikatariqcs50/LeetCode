//Last Solved on: 17 Oct, 2026, Saturday
//Last Solved in: 1 hour

class Solution {
private:
    bool areFreqsEqual(vector<int>& a, vector<int>& b){
        for(int i=0; i<26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()){
            return false;
        }

        int n = s1.length();

        vector<int> freq1(26, 0);
        for (int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
        }

        int left = 0;
        int right = 0;

        vector<int> freq2(26, 0);

        while (right < s2.length()) {
            freq2[s2[right] - 'a']++;
            
            if(right - left + 1 == s1.size()){
                if(areFreqsEqual(freq1, freq2)) return true;
            }

            if(right - left + 1 < s1.size()){
                right++;
            }
            else{
                freq2[s2[left] - 'a']--;
                left++;
                right++;
            }
        }
        return false;
    }
};

//Pattern: Sliding Window
//Save the freqs of chars of s1 in freq1 array
//Save the freqs of chars of current window of s2 in freq2 array
//when current window = size of s1: compare both freqs: if same, return true;
//If not same, remove the left char and add right char