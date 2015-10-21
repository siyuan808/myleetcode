#include <iostream>
#include <vector>

using namespace std;

void zigzagPrintMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(); if(m==0) return;
    int n = matrix[0].size(); if(n == 0) return;
    
    for(int j = 0; j < n; j++) {
        for(int i = 0; j-i>=0; i++) {
            cout <<matrix[i][j-i]<<" ";
        }
        cout <<endl;
    }
    
    for(int i = 1; i < m; i++) {
        for(int j = 0; i+j < m; j++) {
            cout <<matrix[i+j][n-1-j]<<" ";
        }
        cout <<endl;
    }
}

int main(){
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    zigzagPrintMatrix(matrix);
    return 0;
}
