/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        stack<TreeNode*> st;
        TreeNode* current = root;
        while(true){
            
        while(current != nullptr){
            
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            if(current->right)
            st.push(current->right);            
            current = current->left;
            
        }
        if(st.empty()) break;
        current = st.top();
        st.pop();
        }
        return root;
    }
};