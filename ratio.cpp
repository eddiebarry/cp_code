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
ll gcd(ll a, ll b){
    return b==0?a:gcd(b,a%b);
}

/********** Main()  function **********/
int main()
{
    
    ll t = SI();
    while(t--){
        ll n = SI();
        VII v;
        ll num_a = 0;
        ll num_b = 0;
        REP(i,n){
            ll x = SI();
            char c;
            cin>>c;
            if(c=='A'){
                num_a+=x;
            }
            else{
                num_b+=x;
            }
            v.PB(MP(x, c- 'A'));
        }
        // cout<<num_a<<" "<<num_b<<"\n";
        // cout<<gcd(num_a,num_b)<<"\n";  

        //handle 0 case
        if(num_a==0 || num_b == 0){
            ll an =num_a==0?num_b:num_a;
            cout<<an<<"\n";
            continue;
        }

        ll div = gcd(num_a,num_b);
        ll rat_a = num_a/div;
        ll rat_b = num_b/div;
        cout<<rat_a<<" "<<rat_b<<"\n";
        // assert(rat_a>0 && rat_b > 0);
        ll ans = 0;
        ll n_a = 0, n_b = 0;
         a_add = true;
        ll start = -1;
        REP(i,n){
            if(start == -1){
                start = v[i].second;
            }
            if(v[i].second==1){
                a_add = false;
                n_b += v[i].first;
            }
            else{
                a_add = true;
                n_a += v[i].first;
            }
            //check if letter other than start is divisible
            
            //check how it is affected by current addition

        }
        // cout<<ans<<"\n";

    }
    
    return 0;
}


            // // if(n_a / rat_a >=1 && n_b /rat_b >= 1){
            // //     ans += 1;
            // //     n_a -= min(n_a/rat_a, n_b/ rat_b)*rat_a;
            // //     n_b -= min(n_a/rat_a, n_b/ rat_b)*rat_b;
            // // }
            // if(n_a % rat_a ==0 && n_a >= 1 && !a_add && i > 0){
            //     //calculate how much should n_b be
            //     ll a_num = n_a/ rat_a;
            //     ll b_num = a_num * rat_b;
            //     if(b_num <= n_b){
            //         n_a = 0;
            //         n_b -= b_num;
            //         ans++;
            //     }
            // }
            // if(n_b % rat_b ==0 && n_b >= 1 && a_add && i > 0){
            //     //calculate how much should n_b be
            //     ll b_num = n_b/ rat_b;
            //     ll a_num = b_num * rat_a;
            //     if(a_num <= n_a){
            //         n_b = 0;
            //         n_a -= a_num;
            //         ans++;
            //     }
            // }
