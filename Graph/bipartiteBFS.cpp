// Odd length edge cycle graph cannot be a bipartite
// Time Complexity: O(N) + O(2E),
// Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

// Space Complexity: O(3N) ~ O(N),
// Space for queue data structure visited array and an adjacency list

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph, int start, int color[]) {
    int V = graph.size();
    //vector<int> color(V, -1); // Initialize all vertices with color -1 (unvisited)

    queue<int> q;
    q.push(start);
    color[start] = 0; // Start with color 0 for the starting vertex

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (color[v] == -1) { // Unvisited vertex
                color[v] = 1 - color[u]; // Assign the opposite color
                q.push(v);
            } else if (color[v] == color[u]) {
                return false; // If adjacent vertices have the same color, the graph is not bipartite
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    int color[V];
    for(int i=0;i<V;i++) color[i]=-1;

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            if (!isBipartite(graph, i, color))
                return false;
        }
    }

    return true;
}

int main() {
   int V = 4;

    vector<vector<int>> graph(V);

        graph[0].push_back(1);
        graph[1].push_back(0);

        graph[1].push_back(2);
        graph[2].push_back(1);

        //graph[0].push_back(2);
        //graph[2].push_back(0) ;


    if (isBipartite(graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
