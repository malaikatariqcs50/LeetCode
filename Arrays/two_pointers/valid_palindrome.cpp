class Solution {
    public:
        bool isPalindrome(string s) {
                int left = 0;
                        int right = s.length() - 1;

                                while(left < right) {
                                            if(!isalnum(s[left])) {
                                                            left++;
                                                                        }
                                                                                    else if(!isalnum(s[right])) {
                                                                                                    right--;
                                                                                                                }
                                                                                                                            else {
                                                                                                                                            if(tolower(s[left]) != tolower(s[right])) {
                                                                                                                                                                return false;
                                                                                                                                                                                }
                                                                                                                                                                                                left++;
                                                                                                                                                                                                                right--;
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                            return true;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                };

                                                                                                                                                                                                                                                //Last Solved on: 27 Sept 2026
                                                                                                                                                                                                                                                //Last Solved in: 10 minutes
                                                                                                                                                                                                                                                //Trigger: "Need to compare/process something from both ends → think two pointers."
                                                                                                                                                                                                                                                
}