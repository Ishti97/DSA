#include<bits/stdc++.h>
using namespace std;

vector<int> mergeNow(vector<int> &arr, int low, int mid, int high){
    vector<int> tmp;
    int left = low, right = mid+1;

    while(left<=mid && right<=high){

        if(arr[left] <= arr[right]){
            tmp.push_back(arr[left]);
            left++;
        }
        else{
            tmp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
         tmp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        tmp.push_back(arr[right]);
        right++;
    }


    for(int i=low; i<=high; i++){
        arr[i] = tmp[i - low];
    }

    return arr;
}

vector<int> mergeSort(vector<int> &arr, int low, int high){
    if(low < high){
         int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        mergeNow(arr, low, mid, high);
    }
    return arr;
}

int main(){
    vector<int> arr={4,7,6,2,4,8,4,2,5,7,2,7};
    int sz = arr.size();
    vector<int> ans = mergeSort(arr, 0, sz-1);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<< " ";
    return 0;
}
