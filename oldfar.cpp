/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Edgar Monis
 * Handle: the_kng_in_the_!~th
 *
 */
#include<bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define read(type) readInt<type>()
#define ll long long
typedef pair< ll, ll> PII;
typedef vector<ll> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<ll,ll> MPII;
typedef set<ll> SETI;
typedef multiset<ll> MSETI;

ll SI(){
    ll x;
    cin>>x;
    return x;
}


/********** Main()  function **********/
int main()
{
    
    
    ll t = SI();
    while(t--){
        ll n = SI(), m = SI();
        std::vector<ll> row_sum(n,0);
        std::vector<ll> pref_sum(n,0);

        ll pref = 0;
        REP(i,n){
            ll row = 0;
            REP(j,m){
                ll x = SI();
                if(j == 0){
                    pref+=x;
                    pref_sum[i]=(pref);
                }
                row += x;
            }
            row_sum[i]=row;
        }
        for(auto x : pref_sum){
            cout<<x<<' ';
        }
        ll max = -1;
        REP(i,n-1){
            FOR(j,i+1 , n, 1){
                cout<<i <<" "<<j<<" \n";
                ll ans = row_sum[i]+row_sum[j];
                ans += pref_sum[j-1] - pref_sum[i];
                if(ans > max){
                    max = ans;
                }
            }
        }
        cout<<max<<"\n";


    }
    
    return 0;
}



