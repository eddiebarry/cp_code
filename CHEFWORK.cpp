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
    int n = sI();
    int cost[n];
    REP(i,n){
        cost[i]=sI();
    }
    int min_1 = MOD, min_2= MOD, min_3=MOD;
    REP(i,n){
        int x = sI();
        if(x==1){
            if(min_1>cost[i]){
                min_1 = cost[i];
            }
        }
        else if (x==2){
            if(min_2>cost[i]){
                min_2 = cost[i];
            }

        }
        else{
            if(min_3>cost[i]){
                min_3 = cost[i];
            }

        }
    }
    if(min_3<min_1+min_2){
        cout<<min_3;
    }
    else{
        cout<<min_1+min_2;
    }
}
