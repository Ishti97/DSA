// no neg cycle but neg edge exist
// edges can be in any order
// relax all vertices
// relax V-1 times, after v-1 , i should have answer, still komle there is neg cycle
//[Iter - 1st 0 hlp 1, 2nd 1 help 2, 3rd 2 help 3, 4th 3 help 4... so we have 5 vertex]
// use a distance array and update
// TC - V x E

#include <bits/stdc++.h>
using namespace std;

vector<int> BellmanFord(int n, vector<vector<int>>& edges, int src){
    vector<int> dist(n, 1e8);
    dist[src] = 0;

    for(int i=0;i<n-1;i++) {  // Be aware, bellman ford run N-1 times!!
        for (auto it: edges) {
            int u = it[0], v = it[1], wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    // Nth relaxation to check negative cycle // extra relax loop e komle mane neg cycle
    for (auto it: edges) {
        int u = it[0], v = it[1], wt = it[2];

        if(dist[u] != 1e8 && dist[u] + wt < dist[v])
            return {-1};
    }
    return dist;
}

int main() {
    int V = 6, src = 0;
    vector<vector<int>> adj;
    adj.push_back({0,1,5});
    adj.push_back({1,2,-2});
    adj.push_back({1,5,-3});
    adj.push_back({5,3,1});
    adj.push_back({3,2,6});
    adj.push_back({2,4,-3});
    adj.push_back({3,4,-2});
//    adj.push_back({4,3,-2});
    vector<int> ans = BellmanFord(V, adj, src);

      // Printing the shortest distances from the source vertex
    cout << "Shortest distances from vertex " << src << ":" << endl;
    for (int i = 0; i <V; i++) {
        cout << "Vertex " << i << ": " << ans[i] << endl;
    }
    return 0;
}
