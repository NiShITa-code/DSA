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
    int help(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        }
        int leftPath = max(0, help(root -> left, maxi));
        int rightPath = max(0, help(root -> right, maxi));
        maxi = max((root -> val + leftPath + rightPath), maxi);
        // this function returns which side to go next
        return root-> val + max(leftPath, rightPath);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        help(root, maxi);
        return maxi;
    }
};
