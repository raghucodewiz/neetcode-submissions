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
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> depths;

        TreeNode* cur = root;
        TreeNode* last = nullptr;

        while(!st.empty() || cur)
        {
            if(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                if(cur->right == nullptr || last == cur->right)
                {
                    st.pop();
                    int left = depths[cur->left];
                    int right = depths[cur->right];
                    if(abs(left - right) > 1) return false;
                    depths[cur] = 1 + max(left, right);
                    last = cur;
                    cur = nullptr;
                }else{
                    cur = cur->right;
                }
            }
        }
        return true;
    }
};
