//Last Solved on: 24 Oct, 2026
//Last Solved in: 30 mins

class Solution {
int res = 0;
private:
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = dfs(root->left); 
        int r = dfs(root->right); 
        res = max(res, l+r); 
        return 1 + max(l, r); 
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};

//Pattern: Recursion
//Find the height of the tree each time, (maxHeight between left and right + 1)
//Update the global maximum, which will be leftHeight+rightHeight