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
    void allPaths(TreeNode* root, string path, vector<string> &ans){
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(path);
        }

        if(root->left){
            allPaths(root->left, path+"->"+to_string(root->left->val), ans);
        }

        if(root->right){
            allPaths(root->right, path+"->"+to_string(root->right->val), ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        vector<string> ans;

        allPaths(root, path, ans);

        return ans;
    }
};