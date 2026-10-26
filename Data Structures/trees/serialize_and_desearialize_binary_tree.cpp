//Last Solved on: 26 Oct, 2026
//Last Solved in: 45 minutes

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null";
        }

        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                res += "null,";
            } else {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") {
            return nullptr;
        }
        stringstream ss(data);
        string value;
        getline(ss, value, ',');
        TreeNode* root = new TreeNode(stoi(value));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, value, ',') && value != "null") {
                node->left = new TreeNode(stoi(value));
                q.push(node->left);
            }

            if (getline(ss, value, ',') && value != "null") {
                node->right = new TreeNode(stoi(value));
                q.push(node->right);
            }
        }
        return root;
    }
};