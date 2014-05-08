#include<iostream>
#define R 6
#define C 5
using namespace std;


struct location {
    int x;
    int y;
    int max;

};

int min(int x, int y, int z){
    int min = ( x < y ? x : y);
    return ( min < z ? min : z);
}

struct location maxSubMatrix(int matrix[R][C]){
    int size[R][C];
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if( i == 0 || j == 0){
                size[i][j] = matrix[i][j];
            }
            else
                size[i][j] = 0;
        }
    }

    for(int i = 1; i < R; ++i){
        for(int j = 1; j < C; ++j){
            if( matrix[i][j] == 1){
                size[i][j] = min(size[i-1][j], size[i][j-1], size[i-1][j-1]) +1;
            }
            else
                size[i][j] = 0;
        }
    }

    int maxS = -1;
    struct location l;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(maxS < size[i][j]){
                    maxS = size[i][j];
                    l.x = i;
                    l.y = j;
                    l.max = maxS;
            }
        }
    }

    return l;

}

int main(){
    int matrix[R][C] =
    {
        {0, 1, 1, 0, 1}, 
        {1, 1, 0, 1, 0}, 
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}

     };

    struct location l;
    l = maxSubMatrix(matrix);
    std::cout<<"Maximum size of sub-matrix with all 1 is :"<<l.max<<std::endl;
    std::cout<<"The sub-matrix with all 1:"<<std::endl;
    
    for(int i = l.x-l.max+1; i <= l.x; ++i){
        for(int j = l.y-l.max+1; j <= l.y; ++j){
                std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }


}
