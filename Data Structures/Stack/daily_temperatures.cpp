//Last Solved on: 1 Oct 2026, Thursday
//Last Solved in: 20 mins
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> output(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() &&
                   temperatures[st.top()] < temperatures[i]) {
                    output[st.top()] = i - st.top();
                    st.pop();
            }
            st.push(i);
        }
        return output;
    }
};

//Trick:
//Need to store temperatures which do not yet have a greater temp
//Then assign the difference
//When a greater temp is found, check all the smaller temps