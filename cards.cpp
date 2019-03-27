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
int main()
{
   ll t = sI();
   while(t--){
   	ll n = sI(), k = sI();
   	if(n==1){
   		ll x = sI();
   		cout<<x<<"\n";
   		continue;
   	}
   	multiset<ll> v;
   	ll ans = 0;
   	REP(i,n){
   		ll x = sI();
   		if(x>k){
   			v.insert(x-k);
   			ans +=k;
  		}
  		else{
  			ans+=x;
  		}
   		//trmoving largest elem

   	}
    ll largest;
    if(v.size()>0){
      largest = *(v.rbegin());
      ans += largest;
      v.erase(v.find(largest));
    }
	//
  	while(v.size()>1){
  		// cout<<"size is "<<v.size()<<"\n";
  		//find largest element
  		largest = *v.rbegin();
  		v.erase(v.equal_range(largest).first);
  		//remove second largest element;

  		ll second_largets = *v.begin();
  		v.erase(v.equal_range(second_largets).first);

  		largest -= second_largets;
  		// cout<<"largest - second_largets "<<largest<<endl;
  		if(largest>0){
  			v.insert(largest);
  		}
  	
  	}
  	if(v.size()>0){
  		largest = *v.begin();
  		ans -= largest;
  	}
  	cout<<ans<<"\n";

   }

   return 0;
}