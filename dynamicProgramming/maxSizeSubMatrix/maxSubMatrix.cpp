/*
 *Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
 *
 */

#include<iostream>

#define R 6
#define C 5

struct location{
    int x;
    int y;
    int s;
};

int min(int x, int y, int z){
    int min = (x < y ? x:y);
    return (z < min ? z:min);

}

struct location  maxSubMatrixIndex(int matrix[R][C], int r, int c){
    int size[r][c];
    /*
    each entry S[i][j] represents size of the square sub-matrix with all 1s including M[i][j] where M[i][j] is the rightmost and bottommost entry in sub-matrix.*/
    //copying first column and first row as it is to size matrix
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if( i == 0 || j == 0)
                size[i][j] = matrix[i][j];
            else
                size[i][j] = 0;
        }
    }

    for(int i = 1; i < r; ++i){
        for(int j = 1; j < c; ++j){
                if(matrix[i][j] == 1){
                         size[i][j] = min(size[i-1][j], size[i][j-1], size[i-1][j-1]) + 1;
                }
                else
                    size[i][j] = 0;
        }
    }

    int max = -1;
    struct location l;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(size[i][j] > max){
                max = size[i][j];
                l.x = i;
                l.y = j;
                l.s = max;
            }
        }
    }

    return l;
}

int main(){

    struct location lc;
    int matrix[R][C] =  {{0, 1, 1, 0, 1}, 
                    {1, 1, 0, 1, 0}, 
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};
    lc = maxSubMatrixIndex(matrix,R,C); 

    std::cout<<"MAX:"<<lc.s<<std::endl;
    std::cout<<"lc.x:"<<lc.x<<std::endl;
    std::cout<<"lc.y:"<<lc.y<<std::endl;
    for(int i = lc.x-lc.s+1; i <= lc.x; ++i){
        for(int j = lc.y-lc.s+1; j <= lc.y; ++j){
                std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}


