// TC : O(n) + O(2E)
// Use visiting array, if not visited, Use pair in queue, {node, parent};
// logic is if node is visited and parent not same, means visited from other side
// bfs e, jst queue pair of node-parent hbe!

#include <bits/stdc++.h>
using namespace std;

bool findCycle(vector<int> adj[], int vst[], int src){

    vst[src]=1;

    queue<pair<int,int>> q;
    q.push({src, -1});

    while(!q.empty()){
            int nd = q.front().first;
            int prnt = q.front().second;
            q.pop();

            for(auto it: adj[nd]){
                if(!vst[it]){
                    vst[it] = 1;
                    q.push({it, nd});
                }
                // of someone visited, and not current parent, so you can't visit yourself, prnt!=you,
                //someone else visited
                else if(prnt != it){
                    return true;
                }
            }

    }
    return false;
}

bool findCycleInComponents(int nodes, vector<int> adj[]){

    int vst[nodes];
    for(int i =0;i<=nodes;i++)
        vst[i]=0;

    for(int i=1;i<=nodes;i++){    //having multi-component
        if(!vst[i]){
            if(findCycle(adj,vst, i )==true) return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int src, int dst){
    adj[src].push_back(dst);
    adj[dst].push_back(src);
}

int main(){
    int v = 4;
    vector<int> adjLs[v+1];
    addEdge(adjLs, 1,2);
    addEdge(adjLs, 1,3);
    addEdge(adjLs, 2,4);
    addEdge(adjLs, 3,4);
    cout<<findCycleInComponents(v, adjLs);
    return 0;
}

