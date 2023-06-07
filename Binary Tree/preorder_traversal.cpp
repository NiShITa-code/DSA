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
    void helper(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        ans.push_back(root -> val);
        helper(root -> left, ans);
        helper(root -> right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        /*helper(root, preorder);
        return preorder;*/
        //iterative
        /*TreeNode* node = root;
        stack<TreeNode* > st;
        if (node == NULL) {
            return preorder;
        }
        st.push(node);
        while(!st.empty()) {
            node = st.top();
            preorder.push_back(node -> val);
            st.pop();
            if (node-> right != NULL) {
                st.push(node -> right);
            }
            if (node-> left != NULL) {
                st.push(node -> left);
            }

        }
        return preorder;*/
        // morris iterative
        vector<int> preOrder;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr -> left == NULL) {
                preOrder.push_back(curr -> val);
                curr = curr -> right;
            }
            else {
                TreeNode* prev = curr -> left;
                while (prev -> right != NULL && prev -> right != curr) {
                    prev = prev -> right;
                }
                if (prev -> right == NULL) {
                    prev -> right = curr;
                    preOrder.push_back(curr -> val);
                    curr = curr -> left;
                }
                else {
                    prev -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return preOrder;

    }
};
