// Only goes with DAG
// TC : O(n) + O(E)

// using InDegree -
// For each Node, inc+ its adj nodes inDegree; src node inDegree is always 0, push to queue
//  take off from q, dec- adj nodes inDegree, if 0, push to q!

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){

    int inDegree[V];
    for(int i=0;i<=V;i++){
        inDegree[i]=0;
    }

    for(int i=0;i<V;i++){

        for(auto it:adj[i])
            inDegree[it]++;
    }

    queue<int> q;
    for(int i=0;i<V;i++){

        if(inDegree[i]==0)
            q.push(i);

    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto it:adj[node]){

            inDegree[it]--;

            if(inDegree[it]==0)
                q.push(it);
        }
    }
    return topo;
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
    vector<int> lst = topoSort(v, adjLs);

    for(auto it: lst){
        cout<<it<<"       ";
    }
    return 0;
}



