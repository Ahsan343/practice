#include<iostream>

struct longestSequence{
    int size;
    int ends;
};

struct longestSequence longestIncreasingSequence(int *arr, int n){
    struct longestSequence s;
    int *lis = new int[n];
    for(int i = 0; i < n; ++i)
        lis[i] = 1;

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    s.size = -1;
    s.ends = -1;
    for(int i = 0; i < n; ++i){
        if(lis[i] > s.size){
            s.size = lis[i];
            s.ends = i;
        }
    }

    delete[] lis;
    return s;

}

int main(){

    int seq[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
    int size = (sizeof(seq))/sizeof(seq[0]);
    struct longestSequence s = longestIncreasingSequence(seq, size);
    std::cout<<"Size of longest sequence is :"<<s.size<<" and it ends at index "<<s.ends<<std::endl;
    return 0;
}
