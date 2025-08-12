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
    unordered_map<int, int> inorderIndex; 
    int postIdx; 

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inorderIndex[rootVal];
        root->right = helper(inorder, postorder, idx + 1, right);
        root->left = helper(inorder, postorder, left, idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
};
