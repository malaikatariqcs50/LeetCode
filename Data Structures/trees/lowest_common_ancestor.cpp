//Last Solved on: 25 Oct, 2026, Sunday
//Last Solved in: 15 minutes

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != nullptr){
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }

            else if(p->val > root->val && q->val > root->val){
                root = root->right;
            }

            else{
                return root;
            }
        }        
        return nullptr;
    }
};

//Pattern: BST (all nodes on the left are smaller than all nodes on the right)
//If p and q are both smaller than root, go left
//If p and q are both larger than root, go right
//Otherwise return root