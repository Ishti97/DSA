// if topological sort returns N elements, no cycle
// if returns anything less < N, there is cycle

//Kahn's algo

// TC : O(n) + O(E)


#include <bits/stdc++.h>
using namespace std;


bool topoSort(int V, vector<int> adj[]){

    int inDegree[V]={0};

    for(int i=0;i<V;i++){

        for(auto it:adj[i])
            inDegree[it]++;
    }

    queue<int> q;
    for(int i=0;i<V;i++){

        if(inDegree[i]==0)
            q.push(i);

    }

   int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        cnt++;

        for(auto it:adj[node]){

            inDegree[it]--;

            if(inDegree[it]==0)
                q.push(it);
        }
    }
    if(cnt==V)             // anything less V element, its a cycle cz u can't generate topoSort linear way
        return false;

    return true;
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
  cout<< topoSort(v, adjLs);


    return 0;
}
