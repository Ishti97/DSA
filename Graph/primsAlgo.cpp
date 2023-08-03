// Greedy method
// use PQ!
// TC - ElogE
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);

    int sum = 0;

    //vector<pair<int,int>> pr;

    // {wt, Node}
    pq.push({0, 0});

    while (!pq.empty()){
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;
    //    pr.push_back({})

        for(auto it: adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode])
                pq.push({edW, adjNode});
        }
    }
    return sum;
}

void addEdge(vector<vector<int>> adj[], int src, int dst, int wt){
    adj[src].push_back({dst, wt});
    adj[dst].push_back({src, wt});
}

int main() {
    int v = 5;
    vector<vector<int>> adj[v + 1];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 2, 3, 2);
    addEdge(adj, 2, 4, 2);
    addEdge(adj, 3, 4, 1);
    cout << spanningTree(v, adj);
    return 0;
}
