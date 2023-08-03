
#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;
public:
    DisjointSet(int n){             // make-set er kaj ; parent own set r initial rank;
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i=0; i<=n; i++)
            parent[i] = i;

    }
    int findUltPrnt(int node){         // Find-set
        if(node == parent[node])
            return node;
        return parent[node] = findUltPrnt(parent[node]);
    }

    void unionByRank(int n1, int n2){

        int ultPar1 = findUltPrnt(n1);
        int ultPar2 = findUltPrnt(n2);

        if(ultPar1==ultPar2) return;

        if(rank[ultPar1] > rank[ultPar2])
            parent[ultPar2] = ultPar1;

        else if(rank[ultPar1] < rank[ultPar2])
            parent[ultPar1] = ultPar2;

        else{
            parent[ultPar2] = ultPar1;
            rank[ultPar1]++;
        }
    }
};

int main(){

    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findUltPrnt(3)==ds.findUltPrnt(7))
        cout<<"Same"<<endl;
    else
        cout<<"Not same"<<endl;

    ds.unionByRank(3,7);
      if(ds.findUltPrnt(3)==ds.findUltPrnt(7))
        cout<<"Same"<<endl;
    else
        cout<<"Not same"<<endl;

     return 0;

}
