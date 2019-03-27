#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define ll long long
#define ull unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define ll long long
#define intpair pair<int,int>
#define MP(i,j) make_pair(i,j)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
ll sI(){
   ll c;
   cin>>c;
   return c;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n = sI() , t = sI();
   ll running_sum = 0;
   set <int> s;
   std::vector<ll> v;

   ll  max = MOD;
   REP(i,n){
    int x = sI();
    running_sum+=x;
    s.insert(running_sum);
    v.push_back(x);
    if( x < max){
        max = x;
    }
   }
   ll ans = 0;
   ans += (t / running_sum)*n;
   t%= running_sum;

   label:
   REP(i,n){
    if(t >= v[i]){
        ans++;
        t -=  v[i];
    }
   }
   if(t >= max){
        goto label;
   }
   cout<<ans<<"\n";







   return 0;
}