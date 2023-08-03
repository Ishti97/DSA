// TC : O(n) + O(2E)
// Use visiting array, if not visited, run dfs, check adj nodes
// logic is if node is visited and parent not same, means visited from other side

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[]){

    vis[node] = 1;

    for (auto adjacentNode: adj [node]) {

        if(!vis[adjacentNode]) {
            if(dfs(adjacentNode, node, vis, adj) == true)
                return true;
        }
           // of someone visited, and not current parent, so you can't visit yourself, prnt!=you,
            //someone else visited
        else if(adjacentNode != parent)
            return true;
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {

    int vis[V+1];

    for(int i=0;i<=V;i++){
        vis[i]=0;
    }

    for (int i=1;i<=V;i++) {        // having multi-component

        if(!vis[i]) {
            if(dfs(i, -1, vis, adj) == true) return true;
        }
    }

    return false;
}


void addEdge(vector<int> adj[], int src, int dst){
    adj[src].push_back(dst);
    adj[dst].push_back(src);
}

int main(){
    int v= 6;
     vector<int> adjLs[v+1];

    addEdge(adjLs, 1,2);
    addEdge(adjLs, 2,3);
    addEdge(adjLs, 3,4);
    addEdge(adjLs, 4,5);
    addEdge(adjLs, 5,6);
    addEdge(adjLs, 6,1);

    cout<<isCycle(v, adjLs);
}
