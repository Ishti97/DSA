#include<bits/stdc++.h>
using namespace std;
/// brute-force e n^2 hbe, so best merge sort a simple ekta counter add kra, vry easy :)

int mergeNow(vector<int> &arr, int low, int mid, int high){ ///nlogn r sc - O(n)
    vector<int> tmp;
    int left = low, right = mid+1;
    int cnt = 0;
    while(left<=mid && right<=high){

        if(arr[left] <= arr[right]){
            tmp.push_back(arr[left]);
            left++;
        }
        else{
            tmp.push_back(arr[right]);
            cnt += (mid-left+1);
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

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low < high){
            int mid = (low+high)/2;
            cnt += mergeSort(arr, low, mid);
            cnt += mergeSort(arr, mid+1, high);
            cnt += mergeNow(arr, low, mid, high);
    }
    return cnt;
}


int func(vector<int> &arr, int low, int high){
    return mergeSort(arr, low, high);
}

int main(){
    vector<int> arr = {5,3,2,1,4};
    cout<<func(arr,0, arr.size()-1);
    return 0;
}
