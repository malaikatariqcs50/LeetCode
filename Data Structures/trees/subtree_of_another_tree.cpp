class Solution {
private:
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }

        if (root == nullptr || subRoot == nullptr) {
            return false;
        }

        if (root->val == subRoot->val) {
            return dfs(root->left, subRoot->left) &&
                   dfs(root->right, subRoot->right);
        } else {
            return false;
        }
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        if (root->val == subRoot->val) {
            if (dfs(root, subRoot))
                return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};