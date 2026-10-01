//Last Solved on: 1 Oct 2026, Thursday
//Last Solved in: 20 minutes
class MinStack {
    stack<int> st;
    stack<int> minimumStack;
public:
    MinStack() {}

    void push(int value) {
        if (minimumStack.empty() || value <= minimumStack.top()) {
            minimumStack.push(value);
        }
        st.push(value);
    }

    void pop() {
        if (!minimumStack.empty() && minimumStack.top() == st.top()) {
            minimumStack.pop();
        }
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minimumStack.top(); }
};

//Trigger:
//One minimum could be made by min(minimum, value)
//Many minimums = stack of minimums (value <= minimum.top())
//Need to store duplicate minimums as well