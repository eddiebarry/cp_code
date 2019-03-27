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
        ll n = SI() , k  = SI();
        VI v(n);
        REP(i,n){
            v[i]=SI();
        }
        VI left(n);
        VI rit(n);
        ll prev = -1;
        REP(i,n){
            if(v[i]>k){
                int idx = i;
                i++;
                if(i < n){
                    while(v[i]<=k && i < n-1){
                        i++;
                    }
                }
                left[idx]=i - idx;
                i--;
            }
        }
        REP(i,n){
            if(v[n-1-i]>k){
                int idx = n - 1- i;
                i++;
                if(i > 0){
                    while(v[n-1-i]<=k && n-1-i > 0){
                        i++;
                    }
                }
                rit[idx]=i - idx;
                i--;
            }

        }
        REP(i,n){
            cout<<left[i]<<" ";
        }
        cout<<"\n";
        REP(i,n){
            cout<<rit[i]<<" ";
        }
        cout<<"\n";
        ll max = -1;
        REP(i,n){
            if(left[i]>0){
                ll temp = left[i]+rit[i]+1;
                if(temp>max){
                    max = temp;
                }
            }
        }
        cout<<max<<"\n";
    }
    
    
    return 0;
}



