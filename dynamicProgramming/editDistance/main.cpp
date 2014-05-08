#include<iostream>
#include<cstring>

#define EDIT_COST 1


int min(int a, int b, int c){
    int min = ( a < b ? a : b);
    return ( c < min ? c : min);
}


int EditDistanceDP(char *X, char *Y, int m, int n){
    int **cost = new int*[m];
    for(int i = 0; i < m+1; ++i){
        cost[i] = new int[n+1];
    }
    for(int i = 0; i <=m; ++i){
        for(int j = 0; j <= n; ++j){
            cost[i][j] = -1;
        }
    }

    //base case cost[i][0] = i;
    for(int i = 0; i <= m; ++i)
        cost[i][0] = i;

    //base case cost[0][j] = j
    for(int j = 0; j <= n; ++j)
        cost[0][j] = j;

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cost[i][j] = min( cost[i][j-1] + EDIT_COST, cost[i-1][j]+EDIT_COST, cost[i-1][j-1] + (X[i-1] != Y[j-1])); 
        }
    }
    int result = cost[m][n];
    for(int i = 0; i <= m; ++i)
        delete[] cost[i];
    delete[] cost;
    
    return result;
}

int EditDistanceRecursion( char *X, char *Y, int m, int n )
{
        // Base cases
            if( m == 0 && n == 0 )
                     return 0;
                      
            if( m == 0 )
                     return n;
                               
            if( n == 0 )
                     return m;
                                   
            // Recurse
            int left = EditDistanceRecursion(X, Y, m-1, n) + 1;
            int right = EditDistanceRecursion(X, Y, m, n-1) + 1;
            int corner = EditDistanceRecursion(X, Y, m-1, n-1) + (X[m-1] != Y[n-1]);
                                                    
            return min(left, right, corner);

}
int main(){

    char from[] = "SUNDAY";
    char to[] = "SATURDAY";
    std::cout<<"Min edit distance for converting "<<from<<" to "<<to<<" is:"<<EditDistanceDP(from,to, strlen(from), strlen(to))<<std::endl; 
    std::cout<<"Min edit distance for converting "<<from<<" to "<<to<<" is:"<<EditDistanceRecursion(from,to, strlen(from), strlen(to))<<std::endl; 
    return 0;

}
