#include<iostream>
using namespace std;

void increment(int arr[], int size){
    for(auto& x:arr)
        ++x;
    for(auto x:arr)
        cout<<x<<" ";
    cout<<"\n";
}

int main(){
    int arr[] = {0,1,2,3,4,5};
    increment(arr, 6);
    return 0;

};
