class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i, nums[i]);
        }
        Arrays.sort(nodes, Comparator.comparingInt(a -> a.value));
        int group = 1;
        nodes[0].group = group;
        for (int i = 1; i < n; i++) {
            if (Math.abs(nodes[i].value - nodes[i - 1].value) <= limit) {
                nodes[i].group = group;
            } else {
                nodes[i].group = ++group;
            }
        }
        int[] groupBase = new int[group + 1];
        for (int i = n - 1; i >= 0; i--) {
            groupBase[nodes[i].group] = i;
        }
        int[] groupIndex = new int[n];
        for (Node node : nodes) {
            groupIndex[node.id] = node.group;
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int index = groupBase[groupIndex[i]];
            ans[i] = nodes[index].value;
            groupBase[groupIndex[i]]++;
        }
        return ans;
    }

    private static class Node {
        int id;
        int value;
        int group;

        Node(int id, int value) {
            this.id = id;
            this.value = value;
        }
    }

}