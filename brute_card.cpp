#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <cmath>
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


int MAX = -1;


void swap(int *x, int *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  

int k;


void func(int *arr, int n){

  sort(arr,arr+n);
    ll ans = 0;
    for(int i=0;i<n-1;i++){
      if(arr[i]<=k){
        continue;
      }
      else{
        ll k1 = abs(k-arr[i]);
        arr[i]-=k1;
        arr[i+1]-=k1;
      }
    } 
    for(int i=0;i<n;i++){
      ans+=arr[i];
    }
    if(ans > MAX){
      MAX = ans;
    }
}

void permute(int *a, int l, int r) 
{ 
   int i; 
   if (l == r){
    func(a,r);
   }
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); //backtrack 
       } 
   } 
} 


int main()
{
   ll t = sI();
   while(t--){
   	ll n = sI();
     k = sI();
   	int v[n];
    REP(i,n){
      v[i] = (sI());
    }
    permute(v,0,n-1);
    cout<<MAX<<"\n";
   }


   return 0;
}