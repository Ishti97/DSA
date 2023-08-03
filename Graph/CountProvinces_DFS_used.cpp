// DFS

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[node] = 1;
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj) {

        int sz =  adj.size();

        vector<int> adjLs[sz];

        // to change adjacency matrix to list
        for(int i = 0;i<sz;i++) {
            for(int j = 0;j<sz;j++) {
                // self nodes are not considered
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[sz] = {0};

        int cnt = 0;

        for(int i = 0;i<sz;i++) {
            if(!vis[i]) {
                // counter to count the number of provinces
                cnt++;

               dfs(i, adjLs, vis);
            }
        }
        return cnt;

    }
};

int main() {

    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };


    Solution ob;
    cout << ob.numProvinces(adj) << endl;

    return 0;
}
