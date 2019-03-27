#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<list>
#include<math.h>
#include<stdlib.h>
#include<limits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int main(){
    
    double ans = 3;
    long long t=2;
    REP(i,MOD){
        double temp = 4;
        REP(i,3){
            temp/=(t+i);
        }
        t+=2;
        if(i%2==0){
            ans+=temp;
        }
        else{
            ans-=temp;
        }
    }
    cout<<ans<<"\n";
}
