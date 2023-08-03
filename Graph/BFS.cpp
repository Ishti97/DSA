// Output: 0 1 4 2 3

// Time Complexity: O(N) + O(2E),
// Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

// Space Complexity: O(3N) ~ O(N),
// Space for queue data structure visited array and an adjacency list

// using a visited array & queue!!
// visit src node, push to q, traverse adj node

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        int vis[V+1] = {0};

        vis[3] = 1;

        queue<int> q;
        q.push(3);    // push the initial starting node

        vector<int> bfs;

        while(!q.empty()) {   // iterate till the queue is empty

            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector <int> adj[6];

    int nodes = 5; // 0,1,2,3,4

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(nodes, adj);
    printAns(ans);

    return 0;
}
