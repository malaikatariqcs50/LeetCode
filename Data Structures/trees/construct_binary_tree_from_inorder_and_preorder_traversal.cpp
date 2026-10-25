
class Solution {
unordered_map<int, int> map;
int index = 0;
private:
    TreeNode* dfs(vector<int>& preorder, int start, int end){
        if(start > end) return nullptr;

        int rootValue = preorder[index++];
        TreeNode* root = new TreeNode(rootValue);
        int mid = map[rootValue];

        root->left = dfs(preorder, start, mid - 1);
        root->right = dfs(preorder, mid + 1, end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size()-1);
    }
};