#include <bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> &coins, int V){ /// delete larger values from end
    int n = coins.size();
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {
        // Find denominations
        while (V >= deno[i]) {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> coins ={1, 2, 5, 10, 20, 50, 100, 500, 1000 };
    int trgt = 49;
    func(coins, trgt);
}

