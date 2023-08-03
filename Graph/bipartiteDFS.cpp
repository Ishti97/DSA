// Odd length edge cycle graph cannot be a bipartite
// using straight DFS of color list having {0,1}
// TC -  O(N) +O(2E )
// SC - O(N)

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,int colr, int color[], vector<vector<int>>& adj) {

    color[node] = colr;

    for (auto it : adj[node]) {

        if(color[it] == -1) {
            if(dfs(it, !colr, color, adj) == false){
              return false;
            }
        }
        else if(color[it] == color[node]) {
            return false;
        }

    }
     return true;
}

bool isBipartite(vector<vector<int>>& graph){
    int V = graph.size();

    int color[V];

    for(int i = 0; i<V;i++) color[i] = -1;


    for(int i=0;i<V;i++) {

        // uncolored
        if(color[i]== -1) {
            // run dfs - assign 1st node color 0/1;
            if(dfs(i,0, color, graph) == false){
              return false;
            }
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

        graph[0].push_back(2);
        graph[2].push_back(0) ;


    if (isBipartite(graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
