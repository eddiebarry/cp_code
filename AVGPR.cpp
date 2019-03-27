#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
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


long long map[2001];

int main(){
    long long t = sI();
    REP(i,t){
        long long n = sI();
        REP(i,2001){
            map[i]=0;
        }
        REP(i,n){
            long long x = sI();
            map[x+1000]++;
        }
        long long ans = 0;
        
        for(long long i = -1000; i <=999; i++){
            ans += (map[i+1000]*(map[i+1000]-1))/2;
            for(long long j = i+1; j <=1000; j++){
                if(map[(i+j)/2 + 1000]>0 && (i+j) %2 == 0){
                    ans+= map[i+1000]*map[j+1000];
                }
            }
        }
        cout<<ans<<"\n";
    }
}
