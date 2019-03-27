#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
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
   register int c = getchar();
   bool flag = true;
   if(c=='-'){
       flag =false;
       c = getchar();
   }
   int n = 0;
   for( ; (c<48 || c>57); c = getchar() );
   for( ; (c>47 && c<58); c = getchar() ){
       n = (n<<1) + (n<<3) +c -48;
   }
   if(flag){
       return n;
   }
   else{
       return n*-1;
   }
}

void primeFactors(int n, unordered_map<int,int> &ma) 
{ 
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        ma[2]++;
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            ma[i]++;
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2){
    	    ma[n]++;
    } 
   	    
} 
void primeFactors1(int n, unordered_map<int,int> &ma) 
{ 
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        ma[2]--;
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            ma[i]--;
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2){
    	    ma[n]--;
    } 
   	    
}

ll mod(ll a){
	return a<0?-a:a;
}
  
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t = sI();
   REP(i,t){
   		int n = sI(), m = sI();
   		unordered_map<int,int>fact;
   		unordered_map<int,int>fact2;
   		primeFactors(n,fact);	
   		primeFactors1(m,fact);
   		ll ans = 0;
   		for(auto x:fact){
   			ans += mod(x.second);
   		}
   		cout<<ans<<"\n";
   }
   

   	









   return 0;
}