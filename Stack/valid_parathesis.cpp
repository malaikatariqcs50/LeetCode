//Last Solved on: 1 Oct 2026, Thursday
//Last Solved in: 10 mins
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]); 
            } else {
                if (s[i] == ')' && !st.empty() && st.top() == '(') {
                    st.pop();
                } else if (s[i] == '}' && !st.empty() && st.top() == '{') {
                    st.pop();
                } else if (s[i] == ']' && !st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};

//Trigger:
// Matching/nested pairs → stack. Push opening symbols; closing symbol must
// match the most recent unmatched opening symbol (stack top).