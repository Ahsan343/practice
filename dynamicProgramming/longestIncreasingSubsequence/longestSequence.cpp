#include<iostream>
int longestIncreasingSequence(int *arr, int size){
    int lis[size];
    for(int i = 0; i < size; ++i){
        lis[i] = 1;
    }
    for(int i = 1; i < size; ++i){
        for(int j = 0; j < i; ++j){
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] +1;
            }
        }
    }

    int max  = -1;
    for(int i = 0; i < size; ++i){
            if( max < lis[i] )
                max = lis[i];
    }
    return max;
}

int main(){
    int seq[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    std::cout<<"Size of longest increasing sequence:"<<longestIncreasingSequence(seq,(sizeof(seq)/sizeof(seq[0])))<<std::endl;
    return 0;
}
