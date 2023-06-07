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
// TC O(N) SC O (N)
class Solution {
public:
//recursive
    void helper(TreeNode* root, vector<int>& ans) {
        if (root != NULL) {
            helper(root -> left, ans);
            ans.push_back(root -> val);
            helper(root -> right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        /*vector<int> inorder;
        helper(root, inorder);
        return inorder;*/
        //iterative
        vector <int> inorder;
        stack <TreeNode * > s;
        TreeNode* curr = root;
        while (true) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr -> left;
        } else {
            if (s.empty()) break;
            curr = s.top();
            inorder.push_back(curr -> val);
            s.pop();
            curr = curr -> right;
        }
        }
        return inorder;
    }
   
};
