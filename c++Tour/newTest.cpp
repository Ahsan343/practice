#include<iostream>

void createNew(){
    int *arr;
    arr = new int[5];
}


void populate(){
    /*
    int i =0; 
    for(auto x: {2,4,6,8,10}) {
            arr[i] = x;
            ++i;
    }
    */
    for(int i = 0; i < 5; ++i){
        arr[i] = (i+1)*2;
    }
}

void print(){
    for(auto x:arr)
        std::cout<<x<<" ";
    std::cout<<std::endl;
}

void del(){
   delete[] arr; 
}
int main(){
    createNew();
    populate();
    print();
    del();

    return 0;
}
