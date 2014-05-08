#include<iostream>
#include<climits>

int max(int i , int j){
	return ( (i >=j)?i:j);
}

int traverse(int** mat, int r, int c, int* min){
	if(r<0 || c < 0){
		return -1;
	}
	else if(r==0 && c==0){
		if(mat[r][c] < *min){
			*min = mat[r][c]; 
		}
		return mat[r][c];
	}
	else{
	  int result = (max(traverse(mat,r-1,c,min),traverse(mat,r, c-1,min)));
	  if(result < *min){
		*min = result; 
	  }
	  return result;
	}
}

int minimum(int **matrix, int n, int m){
	int min = INT_MAX;
	traverse(matrix, n-1,m-1,&min);
	return min;
}

int main(){
	int **cost;
	cost = new int*[3];
	for(int i = 0; i < 3; ++i){
		cost[i] = new int[3];
	}
			cost[0][0] = 1;
			cost[0][1] = 2;
			cost[0][2] = 3;
			cost[1][0] = 4;
			cost[1][1] = 8;
			cost[1][2] = 2;
			cost[2][0] = 1;
			cost[2][1] = 5;
			cost[2][2] = 3;

        int min =  minimum(cost, 2,2);
	std::cout<<min<<std::endl;
	return 0;

}
