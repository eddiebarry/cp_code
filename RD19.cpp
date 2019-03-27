#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <iomanip>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
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
        int n = sI();
        vector<int>vec(n);
        
        bool is_one = false;
        REP(i,n){
            vec[i]=sI();
            if(vec[i]==1){
                is_one=true;
            }
        }
        if(is_one){
            cout<<0<<"\n";
            continue;
        }
        else{
            int G = vec[0];
            REP(i,n){
                G=__gcd(G,vec[i]);
            }
            if(G!=1){
                cout<<-1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
        
    }
}
