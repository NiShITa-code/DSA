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

    TreeNode* build1(int inStart, int inEnd, vector<int>&inorder,
    int preStart, int preEnd, vector<int>&preorder, unordered_map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[preStart]);
        int inIdx = mp[node -> val];
        int numLeft = inIdx - inStart;
        node -> left = build1(inStart, inIdx - 1, inorder, preStart + 1, preStart + numLeft, preorder, mp);
        node -> right = build1(inIdx + 1, inEnd, inorder, preStart + numLeft + 1, preEnd, preorder, mp);
        return node;
    }

    TreeNode* build2(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[i]);
        i++;
        node -> left = build2(preorder, i, node -> val);
        node -> right = build2(preorder, i, bound);
        return node;

    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // method 1
        // TC = O (nlogn) + O(n)
        // SC = O(N)
        // we know that inorder traversal of a bt is always sorted
        /*vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map <int, int> mp;
        //now make a bt from inorder and postorder    
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build1(0, inorder.size()-1, inorder, 0, preorder.size() - 1, preorder, mp);*/
        // method 2 
        // use upper bound and property of bst that all smaller elements are on left and all larger elements
        // are on right
        int bound = INT_MAX;
        int i = 0;
        return build2(preorder, i, bound);
    }
};
