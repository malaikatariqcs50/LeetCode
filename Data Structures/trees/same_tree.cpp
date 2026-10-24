//Last Solved on: 24 Oct, 2026, Saturday
//Last Solved in: 10 minutes

class Solution {
private:
    bool dfs(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }

        if(p == nullptr || q == nullptr){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};

//Pattern: Recursion
//Call the recursive function on p, q; traverse to their left and right
//If both are equal, return true; otherwise return false