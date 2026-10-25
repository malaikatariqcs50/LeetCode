//Last Solved on: 25 Oct, 2026
//Last Solved in: 10 minutes

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(root != nullptr || !st.empty()){
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(--k == 0){
                break;
            }
            root = root->right;
        }
        return root->val;
    }
};

//Pattern: The smallest valueis in the left of the left most subtree
//Kepp coming upwards and decremenet k
//When k == 0; The node is out kth smallest element's node