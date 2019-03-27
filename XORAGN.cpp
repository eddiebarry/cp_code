#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#define FOR(i, j, k, in) for (long long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;

long long sI(){
    long long c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    long long n = 0;
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    if(flag){
        return n;
    }
    else{
        return n*-1;
    }
}

int main(){
    long long t = sI();
    REP(i,t){
        long long n = sI();
        long long dig[n];
        REP(i,n){
            dig[i]=sI();
            dig[i]= dig[i]<<1;
        }
        long long ans = dig[0];
        REP(i,n-1){
            ans^=dig[i+1];
        }
        cout<<ans<<"\n";
    }
    
}
