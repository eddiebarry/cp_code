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
        VI v;
        REP(i,n){
            v.push_back(SI());
        }
        VI col;
        REP(i,n){
            col.push_back(SI());
        }
        VII rev;
        REP(i,n){
            rev.PB(MP(v[n-1-i], col[n-1-i]));
        }
        SETI uni;
        int i = 0;
        ll max = rev[0].first;
        ll col1 = rev[0].second;
        uni.insert(col1);
            while(true){
                i++;
                if(i>=n){
                    break;
                }
                if(rev[i].first > max){
                    max = rev[i].first;
                    col1 = rev[i].second;
                    uni.insert(col1);
                }
            }
        cout<<uni.size()<<"\n";
 

    }
    
    return 0;
}



