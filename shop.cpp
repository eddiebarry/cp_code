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
    int n = sI();
    REP(i,n){
        long long arr[7];
        long long a = sI(), b = sI(), c = sI(), d = sI(), e = sI();
        arr[0]= d + c + e + a;
        arr[1]= d + c + c + d + a;
        arr[2]= e + c + c + e + a;
        arr[3]= a + a + e + e + d;
        arr[4]= a + a + e + c;
        arr[5]= a + a + d + c;
        arr[6]= d + c + e + a;
        
        long long min = LONG_MAX;
        REP(i,6){
            if(arr[i]<min){
                min = arr[i];
            }
        }
        cout<<min<<"\n";
    }
}
