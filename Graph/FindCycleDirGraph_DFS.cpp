// TC - O (N+E)
// SC - O(2N) + auxiliary stack for dfs O(N)
// USING - vis array and dfsvis array!

#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> adj[], int vis[], int dfsvis[] ){

    vis[node] = 1;
    dfsvis[node] = 1; // cycle hole 7->8->9->7 ..
                                 // abr 7,means 7 visited=1, dfsvis 7=1, mane current cycle e abr 7, mane cycle, return true


    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkCycle(it, adj,vis,dfsvis)==true)
                return true;
        }
        else if(dfsvis[it]==1)
            return true;
    }
    dfsvis[node] = 0;      // dfs a smne r dfs call na kra gele, fire ahsar smy dfsvis=0 kre dibo

    return false;
}

bool isCycle(int V, vector<int> adj[]){

    int vis[V], dfsVis[V];

    memset(vis, 0, sizeof vis);
    memset(dfsVis, 0, sizeof dfsVis);

    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(checkCycle(i, adj, vis, dfsVis)==true)
                return true;
        }
    }
    return false;
}





void addEdge(vector<int> adj[], int src, int dst){
    adj[src].push_back(dst);
}

int main(){
    int v= 6;
    vector<int> adjLs[v+1];
    addEdge(adjLs, 4,0);
    addEdge(adjLs, 5,0);
    addEdge(adjLs, 5,2);
    addEdge(adjLs, 4,1);
    addEdge(adjLs, 2,3);
    addEdge(adjLs, 3,1);
    cout<< isCycle(v, adjLs);
    return 0;
}
