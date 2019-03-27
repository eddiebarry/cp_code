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

ll dfs(ll start, vector< set<ll> > &negib){
	//check all neigbors;
	ll ans = 0;
	set<ll> to_erase;
	VI to_er;
	for(auto neigbors_current : negib[start]){
		for(auto neigbors_next : negib[neigbors_current]){
			if(negib[neigbors_next].find(start)==negib[neigbors_next].end()){
				ans++;
				// negib[neigbors_current].erase(start);
				to_er.push_back(neigbors_current);
				to_erase.insert(neigbors_current);
			}
		}
	}
	// for(auto x : to_er){
	// 	ll neigbors_current = x;
	// 	negib[neigbors_current].erase(start);
	// }
	// for(auto x : to_erase){
	// 	negib[start].erase(x);
	// }
	return ans;
}



/********** Main()  function **********/
int main()
{
    ll n = SI(), m = SI();
    // set<ll>negib[n];

    std::vector< set<ll> > negib(n,set<ll>() );

    VII edges;

    ll ans = n * (n-1) * (n-2);
    ans /= 6;


    VI freq(n,0);
    REP(i,m){
    	ll x = SI(), y =SI();
    	x--;
    	y--;
    	
    	negib[x].insert(y);
    	negib[y].insert(x);
    	
    	freq[x]++;
    	freq[y]++;
    	edges.push_back(MP(x,y));
    }
    REP(i,m){
    	ll x = edges[i].first;
    	ll y = edges[i].second;
    	if(freq[x]==1 && freq[y]==1){
    		ans -=n;
    		negib[x].erase(y);
    		negib[y].erase(x);
    	}
    }

    ll temp = 0;
    REP(i,n){
    	temp -= dfs(i,negib);
    }
    temp/=2;
    cout<<ans+temp;
    return 0;
}



