/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Denzil Bernard  
 * Handle: 1_mn_RMY
 *
 */

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#include <algorithm>    // for lower_bound, upper_bound and sort 
#include <vector> 

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

ll min (ll a, ll b){
    return a<b ? a:b;
}


ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 


int countunsetbits(int n) 
{ 
    int count = 0;  
      
    // x holds one set digit at a time 
    // starting from LSB to MSB of n. 
    for (int x = 1; x <= n; x = x<<1)  
        if ((x & n) == 0) 
            count++;      
  
    return count;  
} 

int countsetbits(int n) 
{ 
    int count = 0;  
      
    // x holds one set digit at a time 
    // starting from LSB to MSB of n. 
    for (int x = 1; x <= n; x = x<<1)  
        if ((x & n) == 0) 
            count++;      
  
    return count;  
}


ll ans(ll  R, ll V){
	if(R < V){
		return 0;
	}
	VI v(19,0);
	VI r(19,0);
	ll idx = -1;
	ll li = -1;
	REP(i,19){
		v[i]=V%2;
		V/=2;
		r[i]=R%2;
		R/=2;
		if(r[i]==1){
			idx = i;
		}
		if(v[i]==1){
			li = i;
		}
	}
	cout<<"\n";
	REP(i,19){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	REP(i,19){
		cout<<r[i]<<" ";
	}
	cout<<"\n"<<idx<<"\n";
	ll ans = 0;
	REP(i,idx+1){
		if(v[i]==0 && i > 0){
			ll nu = 0;
			RFOR(j,i-1,0,1){
				if(v[j]==0){
					nu++;
				}
			}
			nu--;
			ans+= pow(2,nu);
			cout<<ans<<" is after i"<<i<<"\n";
		}

	}
	return ans;

}

ll LIM  = LONG_LONG_MAX;

/********** Main()  function **********/
int main()
{
    ll t = SI();
    while(t--){
    	ll l = SI(), r = SI(), v = SI();
    	cout<<ans(r,v) - ans(l-1,v)<<"\n";




    }


    return 0;
}




