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
    bool isMirror(TreeNode* leftSub, TreeNode* rightSub){
        if(leftSub==NULL && rightSub == NULL){
            return true;
        }

        if(leftSub==NULL || rightSub==NULL || leftSub->val != rightSub->val){
            return false;
        }

        return isMirror(leftSub->left, rightSub->right) && isMirror(leftSub->right, rightSub->left);
    }
    bool isSymmetric(TreeNode* root) {
       if(root==NULL) return true;

       return isMirror(root->left, root->right);
    }
};