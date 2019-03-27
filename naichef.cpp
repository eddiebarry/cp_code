#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<stdlib.h>  //for rand testing purpose
#define node_labl int
#define node_edge_wt int
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
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
    while(t--){
        int n = sI(), a = sI(), b = sI();
        vector<int>vec(n+1);
        REP(i,n){
            vec[sI()]++;
        }
//        REP(i,n+1){
//            cout<<vec[i]<<" ";
//        }
        double A = vec[a]*1.0/n;
        double B = vec[b]*1.0/n;
        cout<<A*B<<"\n";
    }
}
