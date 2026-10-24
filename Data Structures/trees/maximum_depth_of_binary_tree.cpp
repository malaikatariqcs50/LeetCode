//Last Solved on: 24 Oct, 2026
//Last Solved in: 20 minutes

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        TreeNode* current = root;
        stack<pair<TreeNode*, int>> st;
        int count = 1;
        int maxCount = 0;
        while (true) {
            while (current != nullptr) {
                maxCount = max(maxCount, count);
                if (current->right) {
                    st.push({current->right, count+1}); 
                }
                current = current->left;
                count++;
            }
            if (st.empty()) {
                break;
            }
            current = st.top().first;
            count = st.top().second;
            st.pop();
        }
        return maxCount;
    }
};