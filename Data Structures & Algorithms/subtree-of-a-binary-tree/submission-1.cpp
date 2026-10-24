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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            if(node->val == subRoot->val && isSameTree(node, subRoot))
                return true;
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return false;
    }
};
