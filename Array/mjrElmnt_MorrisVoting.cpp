#include<bits/stdc++.h>
using namespace std;
/// Brute-force n^2
/// Hash TC- O(n) + O(nlogn) for ordered map SC- O(N)
/// Best approach Moore's optimizing extra space -- First find element, nxt check element is >n/2
int major(vector<int> &v){
    int cnt = 0, element;

    for(int i=0; i<v.size(); i++){
        if(cnt == 0){
            cnt = 1;
            element = v[i];            /// count 0 mane new element assign ager sb +- kre 0 hoise
        }
        else if(v[i] == element) cnt++;
        else cnt--;
    }

    cnt = 0;

    for (int i=0; i<v.size(); i++){
        if(v[i]== element) cnt++;
    }
    if(cnt> (v.size() / 2)) return element;

    return -1;
}

int main(){
    vector<int> arr = {7,7,7,7,4,3,2,7,5};
    cout<<major(arr);
    return 0;
}

