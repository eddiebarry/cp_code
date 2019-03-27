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
        ll n = SI(), m = SI(), x = SI(), y = SI();
        ll ans = 0;
        REP(i,n){
            REP(j,m){
                //check if in way
                ll i_ = i+1;
                ll j_ = j+1;
                if(i_==x && j_ == y){
                    continue;
                }
                //find num_occupied by queen
                ll upper = n-i_;
                ll lower = i_ - 1;
                ll left = m - i_;
                ll right = i_ - 1;
                ll num_not_pos = upper + lower + left + right;
                //check if 
                cout<<i_<<" "<<j_<<" "<<num_not_pos<<"\n";
                    


            }
        }
    }
    return 0;
}



