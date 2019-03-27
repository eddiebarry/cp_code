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



void dfs(ll current,vector<bool> & marked, multimap<int,int> &children, vector <VI>  &neigh, ll parent){
	marked[current]=true;

	
	for(auto x : neigh[current]){
		if(!marked[x]){
			children.insert(make_pair(current,x));
			// cout<<x<<" is a child of "<<current<<" in the dfs\n";
			dfs(x,marked,children,neigh,current);
		}
	}
}



ll num(multimap<int,int> &children, ll current, VI & col, ll g){
	ll ans = 0;
	auto ret = children.equal_range(current);
	for(auto it= ret.first; it != ret.second; ++it){
		int x = it->second;
		// cout<<x<<" is a child of "<<current<<"\n";
		ans += num(children,x, col, g);
	}
	if(col[current]%g==0){
		ans++;
	}
	return ans;
}

/********** Main()  function **********/
int main()
{
    
    
    ll n = SI();
    VI col(n);
    REP(i,n){
    	col[i]=SI();
    }
    vector< vector<ll> > neig(n, vector<ll>(0));
    REP(i,n-1){
    	ll x = SI(), y = SI();
    	x--, y--;
    	neig[x].push_back(y);
    }
    //dfs
    multimap<int,int> children;
    std::vector<bool> marked(n,false);
    dfs(0,marked,children,neig,0);

    ll q = SI();
    REP(i,q){
    	ll x = SI();
    	if(x == 1){
    		ll n = SI(), y = SI();
    		col[n-1]=y;
    	}
    	else{
    		ll current = SI(), g = SI();
    		ll an = num(children, current-1,col, g);
    		an *= (an -1);
    		an /= 2;
    		cout<<an<<"\n";
    	}
    }


    return 0;
}

// 4
// 2 3 4 4
// 1 2
// 1 3
// 3 4
// 3
// 2 1 2
// 2 3 2
// 1 2 3

