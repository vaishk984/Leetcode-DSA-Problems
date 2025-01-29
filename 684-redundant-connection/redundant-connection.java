class Solution {
    class UnionFind {
        private int[] parent, rank;

        public UnionFind(int n) {
            parent = new int[n + 1]; // 1-based indexing
            rank = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                parent[i] = i; // Initially, each node is its own parent
                rank[i] = 1;   // Initial rank is 1
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        public boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return false; // Cycle detected
            }

            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        UnionFind uf = new UnionFind(n);

        for (int[] edge : edges) {
            if (!uf.union(edge[0], edge[1])) {
                return edge; // The first edge that creates a cycle
            }
        }

        return new int[0];
    }
}