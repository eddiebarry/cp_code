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

ll num_prime_factors[5000000+1];

void pre_calc(){
    REP(i,5000000){
        ll curr = i+2;
        ll num = 0;
            bool flag = true;
            for(int i = 2 ; i*i <= curr; i++){
                if(curr%i==0){
                    num++;
                    curr/=i;
                    num += num_prime_factors[curr];
                    flag = false;
                    break;
                }
            }
            if(flag){
                num++;
                curr/=curr;
            }
        
        num_prime_factors[i+2]=num;
    }
    REP(i,5000000){
        num_prime_factors[i+1]+=num_prime_factors[i];
    }
}

/********** Main()  function **********/
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = SI();
    pre_calc();
    
    // REP(i,100){
    //     cout<<num_prime_factors[i+1]<<" ";
    // }
    while(t--){
        ll a = SI(), b = SI();
        cout<<num_prime_factors[a]-num_prime_factors[b]<<"\n";
    }
    
    return 0;
}



