
#include <bits/stdc++.h>
using namespace std;

    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int,int>>>adj[times.size()+1];

        //           row vs col
        // row:0   2   1   1
        // row:1   2   3   1
        // row:2   2   4   1

        for(int i =0;i<times.size();i++)
                adj[times[i][0]].push_back({times[i][1], times[i][2]});

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(times.size()+1, 1e9);

        dist[k]=0;
        pq.push({dist[k], k});
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto x:adj[node])
            {
                int ds=x.first;
                int wt=x.second;
                if(dist[ds]>dist[node]+wt)
                {
                    dist[ds]=dist[node]+wt;
                    pq.push({dist[ds],ds});
                }
            }
        }
        int mini = INT_MIN;
        for(int i =1;i<=n;i++)
        {
            if(i!=k && dist[i]==INT_MAX) return -1 ;
            mini =max(mini ,dist[i]);
        }
        return mini;
    }

void addEdge(vector<vector<int>> adj[], int src, int dst, int wt){
    adj[src].push_back({dst, wt});
    //adj[dst].push_back({src, wt});
}
int main() {
    int v = 4;
    vector<vector<int>> adj[v+1];
    addEdge(adj, 2,1,1);
    addEdge(adj, 2,3,1);
    addEdge(adj, 3,4,1 );

    int sum = networkDelayTime(adj, v, 2);
    cout<<sum<<endl;
    return 0;
}

