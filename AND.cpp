#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    register int c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    int n = 0;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = sI();
    
    long long sum = 0;
    REP(i,n){
        sum+= sI();
    }
    
    long long sum1 = 0;
    REP(i,n){
        sum1+= sI();
    }
    if(sum1<=sum){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}

