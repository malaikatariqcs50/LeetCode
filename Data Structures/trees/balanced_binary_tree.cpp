//Last Solved on: 24 Oct, 2026
//Last Solved in: 20 minutes

class Solution {
private:
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = dfs(root->left); 
        if(left == -1){
            return -1;
        }
        int right = dfs(root->right); 
        if(right == -1){
            return -1;
        }

        if(abs(left-right) > 1){
            return -1;
        }

        return 1 + max(left, right); 
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};

//Pattern: Recursion
//Find the max height of left subtree and right subtree
//abs(left-right) > 1; return false;
//Otherwise calculate the new height for the parent 1 + max(left, right);