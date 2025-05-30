#include "../utils/common.hpp"
/*struct Vertex
{
    int val;
    Vertex(int x) : val(x) {}
};*/
class GraphAdjList
{
public:
    unordered_map<Vertex *, vector<Vertex *>> adjList;
    void remove(vector<Vertex *> &vec, Vertex *vet)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == vet)
            {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }
    int size()
    {
        return adjList.size();
    }
    void addVertex(Vertex *vet)
    {
        if (adjList.count(vet))
            return;
        adjList[vet] = vector<Vertex *>();
    }
    void removeVertex(Vertex *vet)
    {
        if (!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        adjList.erase(vet);
        for (auto &adj : adjList)
        {
            remove(adj.second, vet);
        }
    }
    void addEdge(Vertex *vet1, Vertex *vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }
    void remove(Vertex *vet1, Vertex *vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }
    void print()
    {
        cout << "邻接表=" << endl;
        for (auto &adj : adjList)
        {
            const auto &key = adj.first;
            const auto &vec = adj.second;
            cout << key->val << ": ";
            printVector(vetsToVals(vec));
        }
    }
};

// BFS
vector<Vertex *> graphBFS(GraphAdjList &graph, Vertex *startVet)
{
    vector<Vertex *> res;
    unordered_set<Vertex *> visited = {startVet};
    queue<Vertex *> que;
    que.push(startVet);
    while (!que.empty())
    {
        Vertex *vet = que.front();
        que.pop();
        res.push_back(vet);
        for (auto adjVet : graph.adjList[vet])
        {
            if (visited.count(adjVet))
                continue;
            que.push(adjVet);
            visited.emplace(adjVet);
        }
    }
    return res;
}

// DFS
void dfs(GraphAdjList &graph, unordered_set<Vertex *> &visited, vector<Vertex *> &res, Vertex *vet)
{
    res.push_back(vet);
    visited.emplace(vet);
    for (Vertex *adjVet : graph.adjList[vet])
    {
        if (visited.count(adjVet))
            continue;
        dfs(graph, visited, res, adjVet);
    }
}
vector<Vertex *> graphDFS(GraphAdjList &graph, Vertex *startVet)
{
    vector<Vertex *> res;
    unordered_set<Vertex *> visited;
    dfs(graph, visited, res, startVet);
    return res;
}
int main()
{
    Vertex *a = new Vertex(1);
    Vertex *b = new Vertex(2);
    Vertex *c = new Vertex(3);

    GraphAdjList graph;
    graph.addVertex(a);
    graph.addVertex(b);
    graph.addVertex(c);
    graph.addEdge(a, b);
    graph.addEdge(b, c);
    graph.print();

    graph.remove(a, b);
    graph.print();

    graph.removeVertex(b);
    graph.print();
    
    delete a;
    delete b;
    delete c;
    return 0;
}
