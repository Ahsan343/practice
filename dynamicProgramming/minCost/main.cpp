/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.

*/

#include<iostream>
using namespace std;

int min(int a, int b, int c){
    int min = ( a < b ? a : b);
    return (min < c ? min:c);
    
}


int minCost(int cost[3][3], int m , int n){

    int **mat = new int*[m+1];
    for(int i = 0; i < m+1; ++i)
        mat[i] = new int[n+1];

    mat[0][0] = cost[0][0];
    for(int i = 1; i <=m; ++i){
        mat[i][0] = mat[i-1][0] + cost[i][0];
    }

    for(int j = 1; j <= n; ++j){
        mat[0][j] = mat[0][j-1] + cost[0][j];
    }

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            mat[i][j]  = cost[i][j] + min(mat[i-1][j], mat[i][j-1], mat[i-1][j-1]);
        }
    }
    int result = mat[m][n];
    for(int i = 0; i <=m; ++i)
        delete[] mat[i];
    delete[] mat;

    return result;
}


int main(){
     int cost[3][3] = { {1, 2, 3},
                        {4, 8, 2},
                        {1, 5, 3} };
     std::cout<<minCost(cost, 2, 2)<<std::endl;

    return 0;
}
