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
#define MOD 10000000070
using namespace std;

int main(){
    srand(0);
    long MAX_REP = MOD;
//    cout<<MAX_REP<<"\n";
    double inside_circ = 0;
    REP(i,MAX_REP){
        int x1 = rand();
        int y1 = rand();
        
        double x = (double)x1/INT_MAX;
        double y = (double)y1/INT_MAX;
//        cout<<x<<" "<<y<<"\n";
        if( ( (x*x) + (y*y) ) <= 1){
            inside_circ++;
        }
    }
    cout<<(inside_circ/MAX_REP)*4<<" is the best estimate of PI\n";
}
