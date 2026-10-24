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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //simple dfs using stack in order
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});
        while(!st.empty())
        {
            auto [a, b] = st.top();
            st.pop();

            if(!a && !b) continue;
            if(!a || !b || a->val != b->val)
                return false;

            st.push({a->left, b->left});
            st.push({a->right, b->right});
        }
        return true;
    }
};
