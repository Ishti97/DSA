// Use disjoint set
// Sort by weight;
// if parent not same, union them and add wt to sum;
// TC - const (4alpha)
#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
    vector<int> rank, parent;
public:
    DisjointSet(int n){             // make-set er kaj ; parent own set r initial rank;
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i=0; i<=n; i++)
            parent[i] = i;

    }
    int findUltPrnt(int node){         // Find-set
        if(node == parent[node])
            return node;
        return parent[node] = findUltPrnt(parent[node]);
    }

    void unionByRank(int n1, int n2){

        int ultPar1 = findUltPrnt(n1);
        int ultPar2 = findUltPrnt(n2);

        if(ultPar1==ultPar2) return;

        if(rank[ultPar1] > rank[ultPar2])
            parent[ultPar2] = ultPar1;

        else if(rank[ultPar1] < rank[ultPar2])
            parent[ultPar1] = ultPar2;

        else{
            parent[ultPar2] = ultPar1;
            rank[ultPar1]++;
        }
    }
};


int spanningTree(int v, vector<vector<int>> adj[]){

    vector<pair<int, pair<int,int>>> edges;

    for(int i=1; i<=v; i++){
        for(auto it:adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }
    sort(edges.begin(), edges.end());

    DisjointSet ds(v);

    int sum=0;

    for(auto it : edges){
        int wt = it.first;
        int s = it.second.first;
        int d = it.second.second;

        if(ds.findUltPrnt(s) != ds.findUltPrnt(d)){
            sum += wt;
            ds.unionByRank(s,d);
        }
    }


    return sum;
}


void addEdge(vector<vector<int>> adj[], int src, int dst, int wt){
    adj[src].push_back({dst, wt});
    adj[dst].push_back({src, wt});
}
int main() {
    int numVertices = 6;
    vector<vector<int>> adj[numVertices+1];
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 1,5,4);
    addEdge(adj, 2,6,7 );
    addEdge(adj, 3,6,8);
    addEdge(adj, 2,3,3);
    addEdge(adj, 2,4,3);
    addEdge(adj, 3,4,5);
    addEdge(adj, 1,4,1);
    addEdge(adj, 4,5,9 );
    int sum = spanningTree(numVertices, adj);
    cout<<sum;
    return 0;
}
