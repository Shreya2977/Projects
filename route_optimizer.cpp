// A ride-sharing app (like Uber/Ola) must determine:
// 1. The shortest route between two locations
// 2. The optimal pickup point when multiple passengers are available
// 3. Handle traffic weights that change edge costs

// This project models a city map as a weighted graph using adjacency lists and implements:
// Dijkstra → Single-source shortest path
// Floyd–Warshall → All-pairs shortest path
// Multi-source Dijkstra → Find best pickup point

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<vector<pair<int, int>>> adj;

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }
    // 1. DIJKSTRA(Single-source shortest path)
    vector<int> dijkstra(int src)
    {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u])
                continue;
            for (auto &edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    // 2. FLOYD-WARSHALL( All-pairs shortest path)
    vector<vector<int>> floydWarshall()
    {
        const int INF = 1e9;
        vector<vector<int>> dist(V, vector<int>(V, INF));
        for (int i = 0; i < V; i++)
            dist[i][i] = 0;
        for (int u = 0; u < V; u++)
        {
            for (auto &edge : adj[u])
            {
                dist[u][edge.first] = edge.second;
            }
        }
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[j][i])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        return dist;
    }
    // 3. MULTI-SOURCE DIJKSTRA(Best Pick-up Point)
    int bestPickup(vector<int> passengers, int driver)
    {
        vector<int> dist = dijkstra(driver);
        int bestNode = -1, bestCost = INT_MAX;
        for (int p : passengers)
        {
            if (dist[p] < bestCost)
            {
                bestCost = dist[p];
                bestNode = p;
            }
        }
        return bestNode;
    }
};

int main()
{
    int V = 6;
    Graph g(V);
    // sample city map graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 3);
    cout << "===== DIJKSTRA: Shortest path from Node 0 =====\n";
    vector<int> dist = g.dijkstra(0);
    for (int i = 0; i < V; i++)
        cout << "0 -> " << i << " = " << dist[i] << "\n";

    cout << "\n===== BEST PICKUP POINT FOR DRIVER AT NODE 0 =====\n";
    vector<int> passengers = {1, 2, 3, 4, 5}; // driver is at 0 and passengers are at nodes 1,2,3,4,5.
    int best = g.bestPickup(passengers, 0);
    cout << "Best pickup node: " << best << "\n"; // min. dist. from node 0

    return 0;
}