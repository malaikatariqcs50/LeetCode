//Last Solved on: 25 Oct, 2026, Sunday
//Last Solved in: 15 minutes

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            res.push_back(q.back()->val);
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
        return res;
    }
};

//Pattern: BFS + queue
//Do the same level order traversal and push the last node (it would be rightmost node) to the result.