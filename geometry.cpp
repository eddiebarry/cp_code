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
#define PI 3.14159265
#define MOD 1000000007
using namespace std;



int main (){
    int t ;
    cin>>t;
    REP(i,t){
        double x;
        cin>> x;
        x/= sqrt(2);
        
        double theta = acos(x);
        
        cout<<theta*180/PI<<"\n";
        
        cout<<"Case #"<<i+1<<":\n";
        cout<<-0.5<<" "<<0<<" "<<0<<"\n"
        cout<<
    }
}
