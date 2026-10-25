//Last Solved on: 25 Oct, 2026, Sunday
//Last Solved in: 30 mins
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        stack<TreeNode*> st;
        TreeNode* pre = nullptr;

        while(root != nullptr || !st.empty()){
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(pre != nullptr && root->val <= pre->val)
                return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};

//Pattern: DFS
//Every node in the left subtree is smaller than the root
//Make the pre node, the downward node in the left subtree
//Make the pre node, the upward node in the right subtree
//root->val > pre->val