#include<bits/stdc++.h>
using namespace std;

void setZeroes( vector<vector<int>> &matrix){                      /// O(n^2)  SC - O(1)
    int row = matrix.size(), col = matrix[0].size(), col0 = 1;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] == 0){
                matrix[i][0]=0;

                if(j != 0) matrix[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if(matrix[i][j] != 0){
                if(matrix[0][j] == 0 || matrix[i][0] == 0 ) matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int j=0; j<col; j++)
            matrix[0][j] = 0;
    }

    if(col0 == 0){
        for(int i=0; i<row; i++)
            matrix[i][0] = 0;
    }
}

int main(){
    vector<vector<int>> mt ={
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1},
    };
    setZeroes(mt);
    return 0;
}
