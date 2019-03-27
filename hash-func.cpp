#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<math.h>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
#define HASH_SIZE 1000

int hash(int k){
    int f = 618;
    float m = 1000;
    
    float temp = k*f - floor(k*f);
    int x = m*temp;
    
    return x;
}


int main(){
    std::cout<<hash(123456)<<"\n";
    
    return 0;
}
