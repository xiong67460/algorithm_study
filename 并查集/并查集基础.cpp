#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parent, rank, size;

public:
    // 构造函数：初始化 n 个节点
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // 构造函数：使用已有的 parent 数组
    UnionFind(const vector<int> &p)
    {
        parent = p;
        rank.assign(p.size(), 1);
        size.assign(p.size(), 1);
    }

    // 递归查找（不压缩路径）
    int findDirect(int x)
    {
        if (parent[x] == x)
            return x;
        return findDirect(parent[x]);
    }

    // 查找 + 路径压缩
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    // 直接合并（不考虑秩和大小）
    void unionDirect(int x, int y)
    {
        int xRoot = find(x), yRoot = find(y);
        if (xRoot != yRoot)
        {
            parent[yRoot] = xRoot;
        }
    }

    // 按集合大小合并
    void unionBySize(int x, int y)
    {
        int xRoot = find(x), yRoot = find(y);
        if (xRoot != yRoot)
        {
            if (size[yRoot] <= size[xRoot])
            {
                parent[yRoot] = xRoot;
                size[xRoot] += size[yRoot];
            }
            else
            {
                parent[xRoot] = yRoot;
                size[yRoot] += size[xRoot];
            }
        }
    }

    // 按秩合并
    void unionByRank(int x, int y)
    {
        int xRoot = find(x), yRoot = find(y);
        if (xRoot != yRoot)
        {
            if (rank[yRoot] <= rank[xRoot])
            {
                parent[yRoot] = xRoot;
            }
            else
            {
                parent[xRoot] = yRoot;
            }
            if (rank[xRoot] == rank[yRoot])
            {
                rank[xRoot]++;
            }
        }
    }

    // 打印父节点数组
    void printParents()
    {
        cout << "父节点数组: ";
        for (int i = 0; i < parent.size(); i++)
        {
            cout << parent[i] << " ";
        }
        cout << "\n";
    }

    // 判断是否连通
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    int n = 10;
    UnionFind uf(n);

    uf.unionByRank(1, 2);
    uf.unionByRank(3, 4);
    uf.unionByRank(2, 3);
    uf.printParents();
    cout << "1 和 4 是否连通？" << (uf.connected(1, 4) ? "是" : "否") << "\n";
    cout << "1 和 5 是否连通？" << (uf.connected(1, 5) ? "是" : "否") << "\n";

    uf.unionByRank(5, 6);
    uf.unionByRank(4, 5);
    uf.printParents();
    cout << "2 和 6 是否连通？" << (uf.connected(2, 6) ? "是" : "否") << "\n";
    cout << "0 和 9 是否连通？" << (uf.connected(0, 9) ? "是" : "否") << "\n";

    return 0;
}
