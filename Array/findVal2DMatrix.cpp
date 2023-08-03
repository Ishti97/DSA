#include<bits/stdc++.h>
using namespace std;
/// since row-col r sorted, we can think as an sorted array therefore Binary Search logn
/// no temp array SC - O(1)
 bool searchMatrix(vector<vector<int>>& matrix, int target) {           /// O(log n*m) !!!

    if(matrix.size() == 0) return false;

    int row = matrix.size(), col = matrix[0].size();
    int low = 0, high = (row*col) - 1;

    while(low <= high){
        int mid = (low + (high - low) / 2);

        if(matrix[mid/col] [mid % col] == target)               /// row = [mid/col]  col = [mid%col]
            return true;
        if(matrix[mid/col] [mid % col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main(){
    vector<vector<int>> arr = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,50}
    };

    cout<<searchMatrix(arr, 35);
    return 0;
}
