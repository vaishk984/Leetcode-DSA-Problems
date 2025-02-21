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
 class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

class FindElements {
    private HashSet<Integer> values;

    public FindElements(TreeNode root) {
        values = new HashSet<>();
        recoverTree(root, 0); 
    }

    private void recoverTree(TreeNode node, int val) {
        if (node == null) return;
        node.val = val;        // Assign new value
        values.add(val);        // Store in HashSet
        recoverTree(node.left, 2 * val + 1);  // Left child
        recoverTree(node.right, 2 * val + 2); // Right child
    }
    
    public boolean find(int target) {
        return values.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */