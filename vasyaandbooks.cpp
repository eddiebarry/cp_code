#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define MOD 1000000007LL
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
int sI(){
	int c;
	cin >>c;
	return c;
   }
ll v[100000][24];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n = sI();
   std::vector<ll> a;
   std::vector<ll> b;
   int start = 0;

   REP(i,n){
      int x = sI();
      a.push_back(x);
   }
   REP(i,n){
      int x = sI();
      b.push_back(x);
   }
   set <int> ins;
   REP(i,n){
      int till = b[i];
      if(ins.find(till)==ins.end()){
         FOR(j ,start , n + 1, 1){
         ins.insert(a[j]);
         if(a[j]==till){
            cout<<j - start + 1<<" ";
            start = j + 1;
            break;
         }
         }
      }
      else{
         cout<<0<<" ";
      }
   }





   return 0;
}