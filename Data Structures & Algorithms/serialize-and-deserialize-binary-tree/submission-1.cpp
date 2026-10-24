/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string str = "";

        if(!root) return str;
        queue<TreeNode*> q;
        TreeNode* cur = root;   
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front(); q.pop();

            if(node == NULL)
            {
                str += "#,";
            }
            else{
                str+= to_string(node->val);
                str+=",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(std::stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');

            if(str == "#")
            {
                node->left = nullptr;
            }else{
                TreeNode* leftNode = new TreeNode(std::stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#")
            {
                node->right = nullptr;
            }else{
                TreeNode* rightNode = new TreeNode(std::stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
