// Only goes with DAG
// TC : O(n) + O(E)

// using visited array and a stack!
// if node not visited, run dfs!
// if no next call for dfs, which means a node cannot go further next, push to stack!

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], vector<int> adj[], stack<int> &st ){

    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){                          // if adj node not visited, check adj
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);   // adj nodes are all visited or no where to go, push to stack; reverse print will be o/p
}


vector<int> topoSort(int V, vector<int> adj[]){

    int vis[V];
    for(int i=0;i<=V;i++){
       vis[i]=0;
    }

    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i, vis, adj,st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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
