class Solution {
    private Map<Integer, List<Integer>> graph;
    private Map<Integer, Integer> bobTime;
    private int maxProfit = Integer.MIN_VALUE;
    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = amount.length;
        graph = new HashMap<>();
        bobTime = new HashMap<>();

        // Build adjacency list
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            graph.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }

        // Find Bob's path to root
        findBobPath(bob, -1, 0);

        // Alice's DFS to maximize profit
        dfs(0, -1, 0, 0, amount);

        return maxProfit;
    }

    private boolean findBobPath(int node, int parent, int time) {
        if (node == 0) {
            bobTime.put(node, time);
            return true;
        }
        if (!graph.containsKey(node)) return false;

        for (int neighbor : graph.get(node)) {
            if (neighbor == parent) continue;
            if (findBobPath(neighbor, node, time + 1)) {
                bobTime.put(node, time);
                return true;
            }
        }
        return false;
    }

    private void dfs(int node, int parent, int time, int totalProfit, int[] amount) {
        int originalAmount = amount[node];

        // Adjust profit if Bob and Alice meet
        if (bobTime.containsKey(node)) {
            int bobArrival = bobTime.get(node);
            if (bobArrival > time) {
                totalProfit += originalAmount;
            } else if (bobArrival == time) {
                totalProfit += originalAmount / 2;
            }
        } else {
            totalProfit += originalAmount;
        }

        // Leaf node condition (no unvisited children)
        boolean isLeaf = true;
        for (int neighbor : graph.get(node)) {
            if (neighbor == parent) continue;
            isLeaf = false;
            dfs(neighbor, node, time + 1, totalProfit, amount);
        }

        // If Alice stops at a leaf, update max profit
        if (isLeaf) {
            maxProfit = Math.max(maxProfit, totalProfit);
        }
    }
    
}