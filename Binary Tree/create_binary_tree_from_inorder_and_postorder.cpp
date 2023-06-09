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
    TreeNode* helpBuild(vector<int>& postorder, int postStart, int postEnd,
    vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp){
        if (postStart > postEnd || inStart > inEnd) {
            return NULL;
        }
        // last node of postorder will be the first node
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idxInorder = mp[root -> val];
        int leftNum = idxInorder - inStart;
        root -> left = helpBuild(postorder, postStart, postStart + leftNum - 1,
        inorder, inStart, idxInorder - 1, mp);
        root -> right = helpBuild(postorder, postStart + leftNum , postEnd -1, inorder, idxInorder + 1, inEnd, mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = helpBuild(postorder, 0, postorder.size() - 1,
        inorder, 0, inorder.size() - 1, mp);
        return root;
        
    }
};
