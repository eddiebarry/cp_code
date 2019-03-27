
#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    int c = getchar_unlocked();
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


int main(){
    int t = sI();
    REP(i,t){
        int x = sI();
        int small,big;
        for(int i = 1; i * i <= x; i++){
            if(x%i==0){
                small = i;
                big = x/i;
            }
        }
        string ans="";
        REP(i,big){
            ans+="X";
        }
        REP(i,small){
            ans+="D";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
