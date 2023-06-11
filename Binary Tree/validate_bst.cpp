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
    bool valid(TreeNode* root, long min_bound, long max_bound) {
        if (root == NULL) {
            return true;
        }
        if (root -> val >= max_bound || root -> val <= min_bound) {
            return false;
        } else {
            bool left = valid(root -> left, min_bound, root -> val);
            bool right = valid(root -> right, root-> val, max_bound);
            return (left && right);
        }
    }
    bool isValidBST(TreeNode* root) {
        long max_bound = LONG_MAX;
        long min_bound = LONG_MIN;
        return valid(root, min_bound, max_bound);      
        
    }
};
