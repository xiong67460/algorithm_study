#include <bits/stdc++.h>
using namespace std;

class GraphAdjMat
{
private:
    vector<int> vertices;
    vector<vector<int>> adjMat;

public:
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges)
    {
        for (int val : vertices)
        {
            addVertex(val);
        }
        for (const vector<int> &edge : edges)
        {
            addEdgeByValue(edge[0], edge[1]);
        }
    }
    int size() const
    {
        return vertices.size();
    }
    int getIndex(int val) const
    {
        auto it = find(vertices.begin(), vertices.end(), val);
        if (it == vertices.end())
            throw out_of_range("����ֵ������");
        return distance(vertices.begin(), it);
    }
    void addVertex(int val)
    {
        int n = size();
        vertices.push_back(val);
        adjMat.emplace_back(vector<int>(n, 0));
        for (vector<int> &row : adjMat)
            row.push_back(0);
    }
    void removeVertex(int index)
    {
        if (index >= size())
            throw out_of_range("���㲻����");
        vertices.erase(vertices.begin() + index);
        adjMat.erase(adjMat.begin() + index);
        for (vector<int> &row : adjMat)
            row.erase(row.begin() + index);
    }
    void removeVertexByValue(int val)
    {
        int index = getIndex(val);
        removeVertex(index);
    }
    void addEdge(int i, int j)
    {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
            throw out_of_range("���㲻����");
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }
    void removeEdge(int i, int j)
    {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
            throw out_of_range("���㲻����");
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }
    void addEdgeByValue(int val1, int val2)
    {
        int i = getIndex(val1);
        int j = getIndex(val2);
        addEdge(i, j);
    }
    void removeEdgeByValue(int val1, int val2)
    {
        int i = getIndex(val1);
        int j = getIndex(val2);
        removeEdge(i, j);
    }
    bool hasEdge(int i, int j)
    {
        if (i < 0 || j < 0 || i >= size() || j >= size())
            return false;
        return adjMat[i][j] != 0;
    }
    bool hasEdgeByValue(int val1, int val2)
    {
        int i = getIndex(val1);
        int j = getIndex(val2);
        return hasEdge(i, j);
    }
    void printVector()
    {
        cout << "[ ";
        for (int val : vertices)
            cout << val << " ";
        cout << "]" << endl;
    }

    void printVectorMatrix()
    {
        for (const auto &row : adjMat)
        {
            cout << "[ ";
            for (int val : row)
                cout << val << " ";
            cout << "]" << endl;
        }
    }
    void print()
    {
        cout << " �����б� = ";
        printVector();
        cout << " �ڽӾ��� =" << endl;
        printVectorMatrix();
    }
};
int main()
{
    vector<int> vertices = {10, 20, 30, 40, 50, 60};
    vector<vector<int>> edges = {
        {10, 20}, {10, 30}, {20, 30}, {20, 40}, {30, 50}, {50, 60}};

    GraphAdjMat graph(vertices, edges);
    graph.print();
    cout << endl;

    graph.addVertex(70);
    graph.addEdgeByValue(60, 70);
    graph.addEdgeByValue(40, 70);
    graph.print();
    cout << endl;

    graph.removeEdgeByValue(10, 30);
    graph.removeEdgeByValue(20, 40);
    graph.print();
    cout << endl;

    cout << "��(50, 60): " << (graph.hasEdgeByValue(50, 60) ? "����" : "������") << endl;
    cout << "��(10, 30): " << (graph.hasEdgeByValue(10, 30) ? "����" : "������") << endl;
    cout << endl;

    graph.removeVertexByValue(20);
    graph.removeVertexByValue(70);
    graph.print();
    cout << endl;

    return 0;
}
