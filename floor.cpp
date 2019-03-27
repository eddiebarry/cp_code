/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Denzil Bernard  
 * Handle: 1_mn_RMY
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

ll mod(ll a){
    return a<0? -a:a;
}


/********** Main()  function **********/
int main()
{
    
    
    ll n = SI(), h = SI(), a = SI(), b = SI(), k = SI();
    REP(i,k){
        ll t_a = SI(), f_a = SI(), t_b = SI(), f_b = SI();
        ll ans = mod(t_a - t_b) + mod(f_b - f_a);
        if(f_a > b && f_b > b && t_b != t_a ){
            ans += (f_a - b) - mod(f_b - f_a) + (f_b - b);
        }
        else if(f_a < a && f_b < a && t_b != t_a){
            ans += (a - f_a) - mod(f_b - f_a) + (a - f_b);
        }
        cout<<ans<<"\n";
    }

    return 0;
}



