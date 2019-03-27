/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Denzil Bernard  / Edgar Monis
 * Handle: 1_mn_RMY / the_king_in_the_north
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


ll mod(ll a){
	return a<0?-a:a;
}


ll fn(ll a){
	ll t = a;
	ll v = a;

	ll x = 1;
	ll num_ones;
	VI bits;
	// bits.push_back(a%2);
	// a/=2;
	// t/=2;
	// v/=2;

	while(a > 0){


		v -= (x - 1);
		v -= 1;
		v %= (x*2);
		v += 1; 
		
		if( v > x ){
			num_ones = 0;
		}
		else{
			num_ones = v%2;
		}


		bits.push_back(num_ones%2);


		x *= 2;
		a/=2;
		v = t;
	}

	// for(auto x : bits){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";


	ll ans = 0;
	REP(i,bits.size()){
		ans *= 2;
		ans += bits[bits.size()-1-i];
	}

	return ans;
}


ll xnor(ll a, ll b) 
{ 
    // Make sure a is larger 
    if (a < b) 
        swap(a, b);  
  
    if (a == 0 && b == 0)  
        return 1;  
  
    ll a_rem = 0; // for last bit of a 
    ll b_rem = 0; // for last bit of b 
  
    // counter for count bit  
    // and set bit  in xnornum 
    ll count = 0;  
  
    // to make new xnor number 
    ll xnornum = 0; 
  
    // for set bits in new xnor number 
    while (a)  
    { 
        // get last bit of a 
        a_rem = a & 1;  
  
        // get last bit of b 
        b_rem = b & 1;  
  
        // Check if current two 
        // bits are same 
        if (a_rem == b_rem)         
            xnornum |= (1 << count); 
          
        // counter for count bit 
        count++;  
        a = a >> 1; 
        b = b >> 1;  
    } 
    return xnornum; 
}




/********** Main()  function **********/
int main()
{
	ll a = SI(), b = SI();

	if(a==b){
		cout<<a<<"\n";
		return 0;
	}

	ll a_1 = fn(b);
	ll a_2 = fn(a-1);

	// cout<<a_1<<" "<<a_2<<"\n";

	ll ans = (a_2^a_1);

	if(a%2==1 && b%2==0){
		ans += 1;
	}
	else if(a%2==0 && b%2==1){
		ans += 1;
	}
	if(a%2==1 && b%2==1){
		ans = fn(b) ^ fn(a);
	}
	cout<<ans<<"\n";



    
    return 0;
}



