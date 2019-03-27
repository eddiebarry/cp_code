#include <climits>
#include <iostream>
#include <string>
#include <vector>
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
        int m=sI(),n = sI();
        vector< pair<long,long> >vec;
        vec.push_back(make_pair(1,0));
        vec.push_back(make_pair(0,1));
        FOR(i,2,n,1){
            long long x = (vec[i-1].first+vec[i-2].first)%MOD;
            long long y = (vec[i-1].second+vec[i-2].second)%MOD;
            vec.push_back(make_pair(x,y));
        }
        vector<long long> vec1;
        REP(i,m){
            int x = sI();
            vec1.push_back(x);
        }
        long long sum2 = 0;
        vector<long long> vec2;
        REP(i,m){
            int x = sI();
            vec2.push_back(x);
            sum2+=x;
            sum2%=MOD;
        }
        long long ans = 0;
        REP(i,m){
            ans += ((m*vec[n-1].first)%MOD)*vec1[i];
            ans %=MOD;
            ans += ((sum2*vec[n-1].second)%MOD);
            ans %=MOD;
        }
        cout<<ans<<"\n";
    }
}
