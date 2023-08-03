#include <bits/stdc++.h>
using namespace std;

bool findCycle(vector<int> adj[], int vst[], int src){

    vst[src]=1;

    queue<pair<int,int>> q;
    q.push({src, -1});

    while(!q.empty()){
            int nd = q.front().first;
            int pr = q.front().second;

            q.pop();

            for(auto it: adj[nd]){
                if(!vst[it]){
                    vst[it] = 1;
                    q.push({it, nd});
                }
                else if(pr!=it){
                    return true;
                }
            }

    }
    return false;


}


bool findCycleInComponents(int nodes, vector<int> adj[]){

    int vst[nodes]={0};

    for(int i=0;i<nodes;i++){
        if(!vst[i]){
            if(findCycle(adj,vst, i)==true)
                return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int src, int dst){
    adj[src].push_back(dst);
    adj[dst].push_back(src);
}

int main(){
    vector<int> adjLs[6];

    addEdge(adjLs, 1,2);
    addEdge(adjLs, 1,3);
    addEdge(adjLs, 2,4);
    addEdge(adjLs, 3,5);

    int nodes = 5;

    cout<<findCycleInComponents(nodes, adjLs);
}
