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
    int checkBalanced(TreeNode* root){
        if(root == NULL) return 0;

        int heightLeft = checkBalanced(root->left);
        int heightRight = checkBalanced(root->right);

        if(heightLeft==-1 || heightRight==-1 || abs(heightLeft-heightRight) > 1){
            return -1;
        }

        return max(heightLeft, heightRight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return checkBalanced(root) > 0;
    }
};