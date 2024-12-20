/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        if (root == null) return null;
        reverseOddLevels(root.left, root.right, 1); // Start recursion from level 1
        return root;
    }

    private void reverseOddLevels(TreeNode left, TreeNode right, int level) {
        if (left == null || right == null) return;

        // If the level is odd, swap the values
        if (level % 2 == 1) {
            int temp = left.val;
            left.val = right.val;
            right.val = temp;
        }

        // Recurse on the next level
        reverseOddLevels(left.left, right.right, level + 1);
        reverseOddLevels(left.right, right.left, level + 1);
    }
}