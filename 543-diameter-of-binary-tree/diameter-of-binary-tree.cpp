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

    int height(TreeNode* root){
        if(root==nullptr) return 0;

        int rightHeight = height(root -> right);
        int leftHeight = height(root -> left);

        return max(rightHeight, leftHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        int len = height(root->left) + height(root->right);
        int rightLen = diameterOfBinaryTree(root->right);
        int leftLen = diameterOfBinaryTree(root->left);

        int maxLen = max(len, max(rightLen, leftLen));

        return maxLen;
    }
};