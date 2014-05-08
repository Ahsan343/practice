#include<iostream>

int largestSumSofar(int *arr, int n){
    int max_ending_here = 0, max_so_far = 0;
    for(int i = 0; i < n; ++i){
        max_ending_here += arr[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    std::cout<<"Largest sum so far:"<<largestSumSofar(a, 8)<<std::endl;
    return 0;
}
