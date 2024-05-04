#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<vector<int>> adj;
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (auto x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    void bfs_recursive(vector<vector<int>> &adj, vector<bool> &visited, queue<int> &q)
    {
        if (q.empty())
        {
            return;
        }
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
        bfs_recursive(adj, visited, q);
    }
    void dfs_recursive(vector<vector<int>> &adj, vector<bool> &visited2, int node)
    {
        cout << node << " ";
        visited2[node] = true;
        for (auto x : adj[node])
        {
            if (!visited2[x])
            {
                dfs_recursive(adj, visited2, x);
            }
        }
    }
};

int main()
{
    int n = 15;
    Graph g(n);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(5, 9);
    g.addEdge(5, 10);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(7, 11);
    g.addEdge(7, 12);
    g.printGraph();
    vector<bool> visited(15, false);
    queue<int> q;
    cout << "BFS: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            q.push(i);
            g.bfs_recursive(g.adj, visited, q);
        }
    }
    cout << endl;
    cout << "DFS: " << endl;
    vector<bool> visited2(15, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs_recursive(g.adj, visited2, i);
        }
    }
    cout << endl;
}