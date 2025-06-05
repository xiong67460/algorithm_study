import java.util.Arrays;

public class 并查集基础 {
    static class UnionFind {
        private int[] parent, rank, size;

        public UnionFind(int n) {
            this.parent = new int[n];
            this.rank = new int[n];
            this.size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
                size[i] = 1;
            }
        }

        public UnionFind(int[] parent) {
            this.parent = parent;
            this.rank = new int[parent.length];
            this.size = new int[parent.length];
            Arrays.fill(rank, 1);
            Arrays.fill(size, 1);
        }

        public int findDirect(int x) {
            if (parent[x] == x)
                return x;
            return findDirect(parent[x]);
        }

        public int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        public void unionDirect(int x, int y) {
            int xRoot = find(x), yRoot = find(y);
            if (xRoot != yRoot) {
                parent[yRoot] = xRoot;
            }
        }

        public void unionBySize(int x, int y) {
            int xRoot = find(x), yRoot = find(y);
            if (xRoot != yRoot) {
                if (size[yRoot] <= size[xRoot]) {
                    parent[yRoot] = xRoot;
                    size[xRoot] += size[yRoot];
                } else {
                    parent[xRoot] = yRoot;
                    size[yRoot] += size[xRoot];
                }
            }
        }

        public void union(int x, int y) {
            int xRoot = find(x), yRoot = find(y);
            if (xRoot != yRoot) {
                if (rank[yRoot] <= rank[xRoot]) {
                    parent[yRoot] = xRoot;
                } else {
                    parent[xRoot] = yRoot;
                }
                if (rank[xRoot] == rank[yRoot]) {
                    rank[xRoot]++;
                }
            }
        }

        public void printParents() {
            System.out.println("父节点数组: " + Arrays.toString(parent));
        }

        public boolean connected(int x, int y) {
            return find(x) == find(y);
        }

    }
    public static void main(String[] args) {
        int n = 10; 
        UnionFind uf = new UnionFind(n);
        uf.union(1, 2);
        uf.union(3, 4);
        uf.union(2, 3);
        uf.printParents();
        System.out.println("1 和 4 是否连通？" + uf.connected(1, 4)); 
        System.out.println("1 和 5 是否连通？" + uf.connected(1, 5)); 
        uf.union(5, 6);
        uf.union(4, 5);
        uf.printParents();
        System.out.println("2 和 6 是否连通？" + uf.connected(2, 6)); 
        System.out.println("0 和 9 是否连通？" + uf.connected(0, 9)); 
    }

}