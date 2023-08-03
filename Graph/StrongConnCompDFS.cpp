// TC - O(V+E)
// kosaraju algo

// Do toposort using dfs
// transpose adjlst
// get items from stck and run dfs on trans adj list
// stack theke niye vertex joto gulo call kre dfs kre, oitar numbr e graph er SCC!!

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void revDFS(int node, vector<int> &vis, vector<int> trans[]){
    cout<< node<< " ";
    vis[node]=1;

    for(auto it: trans[node]){
        if(!vis[it])
            revDFS(it, vis, trans);
    }
}

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it])
            dfs(it, adj,vis,st);
    }
    st.push(node);
}
void topoSort(int v, vector<int> adj[]){

//    int vis[v];
//    memset(vis,0,sizeof v);

    vector<int> vis(v,0);

    stack<int> st;
    for(int i=0;i<v;i++){
        if(!vis[i])
            dfs(i, adj,vis, st);
    }

    vector<int> transpose[v];

    for(int i=0;i<v;i++){
        vis[i]=0;
        for(auto it : adj[i]){
            // i -> it
            // it -> i
            transpose[it].push_back(i);
        }

    }

    int cnt=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();

        if(!vis[node]){
            cnt++;
            cout<<"SCC: ";
            revDFS(node, vis, transpose);
            cout<<endl;
        }
    }
    cout<<"NUm of SCC: "<<cnt;
}

void addEdge(vector<int> adj[], int src, int dst){
    adj[src].push_back(dst);
}
void print(int v, vector<int> adj[]){
    for(int i=0;i<v;i++){
        cout<<"Adjacency List of Vertex "<< i<< "->";
        for(auto it: adj[i]){
            cout<< it<< " ";
        }cout<<endl;
    }
}
int main(){
    int vertex = 5, edges = 5;
    vector<int> adjLs[vertex];

    addEdge(adjLs, 0,1);
    addEdge(adjLs, 1,2);
    addEdge(adjLs, 2,0);
    addEdge(adjLs, 1,3);
    addEdge(adjLs, 3,4);
    //print(vertex, adjLs);
    topoSort(vertex, adjLs);
     return 0;

}
