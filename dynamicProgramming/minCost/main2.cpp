#include<iostream>
#define R 3
#define C 3

int min(int a, int b, int c){
    int min = a < b ? a : b;
    return (c < min ? c : min);
}

int minCost(int cost[R][C], int m, int n){
    int matrix[m+1][n+1];
    matrix[0][0] = cost[0][0];
    for(int i = 1; i <= m; ++i){
        matrix[i][0] = matrix[i-1][0] + cost[i][0];
    }

    for(int j = 1; j <= n; ++j){
        matrix[0][j] = matrix[0][j-1] + cost[0][j];
    }

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            matrix[i][j] = min(matrix[i-1][j], matrix[j][i-1], matrix[i-1][j-1]) + cost[i][j];
        }
    }
    return matrix[m][n];

}

int main(){


    int cost[R][C] = {
                {1,2,3},
                {4,8,2},
                {1,5,3}
    };
    std::cout<<minCost(cost, 2,2)<<std::endl;
    return 0;
}
