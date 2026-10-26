//Last Solved on: 26 Oct, 2026, Monday
//Last Solved in: 45 mins

class Solution {
    int maxSum = INT_MIN;
private:
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        maxSum = max(maxSum, root->val+left+right);

        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

//Pattern: Recursion, bottom up
//Find the max Path of a subtree and keep going up