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
        TreeNode* node = root;
        TreeNode* last = nullptr;
        unordered_map<TreeNode*, int> height;
        while(!st.empty() || node)
        {
            if(node){
                st.push(node);
                node = node->left;
            }else{
                TreeNode* curNode = st.top();
                if(curNode->right && last != curNode->right)
                {
                    node = curNode->right;
                }else{
                    st.pop();
                    int left = curNode->left? height[curNode->left] : 0;
                    int right = curNode->right? height[curNode->right] : 0;
                    if(abs(left-right)>1) return false;
                    height[curNode] = 1 + max(left,right);
                    last = curNode;
                    node = nullptr;
                }
            }
        }
        return true;
    }
};
