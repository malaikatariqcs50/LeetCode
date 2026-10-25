//Last Solved on: 25 Oct, 2026, Sunday
//Last Solved in: 25 mins

class Solution {
private:
    int dfs(TreeNode* root, int maxValue){
        if(root == nullptr){
            return 0;
        }

        int currentCount = 0;
        if(root->val >= maxValue){
            currentCount = 1;
            maxValue = root->val;
        }

        int left = dfs(root->left, maxValue);
        int right = dfs(root->right, maxValue);

        return currentCount + left + right;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};

//Pattern: Dfs
//If the current node's value is greater than the max Value, it is a good node and keep the loop going after making the current node's value the greatest
//If it is not greater, it is not a good node and the greatest value stays the same and keep checking downwards for a node reater than the max node's value