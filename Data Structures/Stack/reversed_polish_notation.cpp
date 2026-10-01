//Last solved on: 1 oct 2026, Thursday 
//Last Solved in: 13 minutes
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> st;
       for(int i=0; i < tokens.size(); i++){
           int n1 = 0;
           int n2 = 0;
           if(tokens[i] == "+"){
               n2 = st.top();
               st.pop();
               n1 = st.top();
               st.pop();
               st.push(n1+n2);
           }
           else if(tokens[i] == "-"){
               n2 = st.top();
               st.pop();
               n1 = st.top();
               st.pop();
               st.push(n1-n2);
           }
           else if(tokens[i] == "*"){
               n2 = st.top();
               st.pop();
               n1 = st.top();
               st.pop();
               st.push(n1*n2);
           }
           else if(tokens[i] == "/"){
               n2 = st.top();
               st.pop();
               n1 = st.top();
               st.pop();
               st.push(n1/n2);
           }
           else{
               int num = stoi(tokens[i]);
               st.push(num);
           }
       }
       return st.top();
    }
};

//Trigger:
//Reversing + remembering -> stack