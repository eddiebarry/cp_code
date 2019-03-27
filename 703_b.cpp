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
    
    
    ll n = SI(), k = SI();
    VI v(n);
    unordered_set <ll> mp;
    ll sum1 = 0;
    REP(i,n){
        int x = SI();
        sum1 +=x;
        v[i]=x;
    }
    ll sum_caps = 0;
    REP(i,k){
        int x = SI();
        mp.insert(x);
        sum_caps += v[x-1];
    }
    sum1 -= sum_caps;



    ll one_sum = 0;
    ll sum = 0;
    REP(i,n){
        int curr = i+1;
        if(mp.find(curr)!=mp.end() ){
            sum += sum1 *v[i];
            one_sum += (sum_caps - v[i])*v[i];
        }
        else{
            ll front = i+1;
            front%=n;
            if(mp.find(front+1)==mp.end()){
                sum += v[front]*v[i];
            }
        }
    }
    // cout<<one_sum<<" "<<sum<<"\n";
    one_sum/= 2;
    cout<<one_sum+sum;
    
    return 0;
}



