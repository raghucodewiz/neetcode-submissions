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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> mp;

        mp[nullptr] = {0, 0};
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* cur = st.top();
            if(cur->left && mp.find(cur->left) == mp.end())
            {
                st.push(cur->left);
            }
            else if(cur->right && mp.find(cur->right) == mp.end())
            {
                st.push(cur->right);
            }
            else{
                cur = st.top();
                st.pop();

                auto [leftHeight, leftDiameter] = mp[cur->left];
                auto [rightHeight, rightDiameter] = mp[cur->right];

                int height = 1 + max(leftHeight, rightHeight);
                int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

                mp[cur] = {height, diameter};
            }
        }
        return mp[root].second;
    }
};
