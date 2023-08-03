// uSe PQ!
//TC - ElogV
// use a distance array and update
// relax adj vertex
// use q or set to find smallest distances

#include <bits/stdc++.h>
using namespace std;



// Using Set
vector<int> dijkstra(int vertex, vector<vector<int>> adj[], int src){
    vector<int> dist(vertex, 1e9);
    set<pair<int,int>> st;

    st.insert({0, src});
    dist[src] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto itr: adj[node]){
            int adjNode = itr[0];
            int edgWt = itr[1];

            if(dis + edgWt < dist[adjNode]){
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

// Using PQ
vector<int> dijkstraPQ(int vertex, vector<vector<int>> adj[], int src){
    vector<int> dist(vertex, 1e9);
    priority_queue<pair<int,int>,
            vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto itr: adj[node]){
            int adjNode = itr[0];
            int edgWt = itr[1];

            if(dis + edgWt < dist[adjNode]){
                dist[adjNode] = dis + edgWt;
               pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
void addEdge(vector<vector<int>> adj[], int src,
             int dst, int wt){

    adj[src].push_back({dst, wt});
   // adj[dst].push_back({src, wt});
}
int main() {
    int numVertices = 7;

    vector<vector<int>> adj[numVertices+1];


    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 2, 3,2 );
    addEdge(adj, 2, 4, 1);
    addEdge(adj, 2, 5, 3);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 4, 6, 3);
    addEdge(adj, 3, 6, 1);

    int src = 0;  // Source vertex for Dijkstra's algorithm

    vector<int> shortestDistances = dijkstraPQ(numVertices, adj, src);

    // Printing the shortest distances from the source vertex
    cout << "Shortest distances from vertex " << src << ":" << endl;
    for (int i = 0; i <numVertices; i++) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
