#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    register int c = getchar_unlocked();
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





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = sI();
    while(t--){
        int n = sI();
        vector<long> vec;
        long long ans = 0;
        REP(i,n){
            vec.push_back(sI());
        }
        sort(vec.begin(), vec.end());
        vector< long long > DP;
        DP.push_back(1);
        REP(i,n-1){
            long long temp = DP[i];
            long long curr_mult = i+2;
            temp*=curr_mult;
            temp%=MOD;
            DP.push_back(temp);
        }
        long long ans = 0;
        REP(i,n){
            ans+= (vec[n-1-i]*DP[i])%MOD;
            ans%=MOD;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}

