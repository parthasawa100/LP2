#include <bits/stdc++.h>
#define INF INT_MAX
#define vertices 5

using namespace std;

int minimum_key(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

void prim(const vector<vector<int>>& graph) {
    vector<int> parent(vertices);
    vector<int> key(vertices, INF);
    vector<bool> mstSet(vertices, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minimum_key(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "\n Edge \t  Weight\n";
    for (int i = 1; i < vertices; i++)
        cout << " " << parent[i] << " <-> " << i << "    " << graph[i][parent[i]] << "\n";
}

int main() {
    vector<vector<int>> graph = {{0, 0, 3, 0, 0},
                                 {0, 0, 10, 4, 0},
                                 {3, 10, 0, 2, 6},
                                 {0, 4, 2, 0, 1},
                                 {0, 0, 6, 1, 0}};

    prim(graph);
    return 0;
}
