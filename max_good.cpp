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
    
    
    ll n = SI();
    VI v(n);
    REP(i,n){
        v[i]=SI();
    }
    VI zer(n+1,0);
    VI one(n+1,0);
    ll num_zero = 0;
    ll num_one = 0;
    REP(i,n){
        if(v[i]==0){
            num_zero++;
        }
        else{
            num_one++;
        }
        zer[i+1]=num_zero;
        one[i+1]=num_one;
    }
    // for(auto x: zer){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    // for(auto x: one){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    ll max = -1;
    ll length = -1;

    REP(i,n){
        FOR(j,i+1,n+1,1){
            // cout<<j<<" "<<i<<"\n";
            ll tot_zer = zer[j] - zer[i];
            ll tot_one = one[j] - one[i];

            ll ans = tot_one - tot_zer;
            if(ans==max){

                ll temp = j -i;
                if(temp > length){
                    length = temp;
                }
            }
            else if (ans > max){
                max = ans;
                ll temp = j -i;
                length = temp;
            }
        }
    }
    cout<<length<<"\n";
    return 0;
}



