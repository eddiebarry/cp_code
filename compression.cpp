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

int arr[5200][5200];
// int cache[51200][51200];
ll N = 5200;
ll M = 5200;


void precomputeCache()
{
    // Store the sum of elements in individual rows
    for(int i=0; i<N; i++)
    {
        int sum = 0;
        for(int j=0; j<M; j++)
        {
            sum += arr[i][j];
            arr[i][j] = sum;
        }
    }
    
    for(int i=1; i<N; i++)
    {
        for(int j=M-1; j>=0; j--)
        {
            arr[i][j] += arr[i-1][j];
        }
    }
}
int regionSum(int si, int sj, int ei, int ej)
{
    int sum = arr[ei][ej];
    
    if(si > 0)
        sum -= arr[si-1][ej];
    if(sj > 0)
        sum -= arr[ei][sj-1];
    if(si > 0 && sj > 0)
        sum += arr[si-1][sj-1];
    
    return sum;
}

bool check(int k, ll n){
	for(int i = 0; i < n; i+= k){
		for(int j = 0; j < n; j += k){
			ll x = regionSum(i,j,i+k-1, j + k-1);
			// cout<<"sum is "<<x<<" "<<i<<" "<<j<<i+k<<" "<<j+k<<"\n";
			if( x == k*k || x == 0){
				continue;
			} 
			else{
				return false;
			}
		}
	}
	return true;
}


/********** Main()  function **********/
int main()
{
    ll n = SI();
    getchar();
    REP(i,n){
    	REP(j,n/4){
    		char c;
    		c = getchar();
    		ll num;
    		if(isalpha(c)){
    			num = c - 'A' + 10;
    		}
    		else{
    			num = c - '0';
    		}
    		arr[i][j*4+3] = num%2;
    		num/=2;
    		arr[i][j*4+2] = num%2;
    		num/=2;
    		arr[i][j*4+1] = num%2;
    		num/=2;
    		arr[i][j*4] = num%2;
    		num/=2;
    	}
    	getchar();
    }

    precomputeCache();
    set<ll>fact;
    for(int i = 1; i * i <= n; i++){
    	if(n%i==0){
    		fact.insert(-i);
    		fact.insert(-n/i);
    	}
    }
    for(auto x : fact){
    	if(check(-x, n)){
    		cout<<-x<<"\n";
    		break;
    	}
    }
    return 0;
}



