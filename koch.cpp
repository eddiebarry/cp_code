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

/*******  Aint Required define Pre-Processors and typedef Constants *******/
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define aint(cont) cont.begin(), cont.end()
#define raint(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define read(type) readInt<type>()
// #define int long long
typedef pair< int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;

int SI(){
    int x;
    cin>>x;
    return x;
}

int gcd(int a, int b){
	return a == 0? b: gcd(b%a,a);
}


int mod(int a){
	return a<0?-a:a;
}


/********** Main()  function **********/
int main()
{
    int t = SI();
    while(t--){
        int n = SI();
        MPII freq;
        int v[n];
        REP(i,n){
        	int num = SI();
        	v[i]=(num);	
     
        	freq[num]++;
        }
        int ans = 0;
        REP(i,n){
        	REP(j,n){
        		if(v[i]==v[j]){
        			continue;
        		}
        		// cout<<i<<" "<<j<<" "<<v[i]<<" "<<v[j]<<"\n";

        		int f = v[i];
        		int l = v[j];

        		int m = v[j] + v[j] - v[i];

        		int num_r = m / gcd(l,m);
        		int deno_r = l / gcd(l,m);

        		int k = m * num_r;
        		if(k%deno_r==0){
        			k /=deno_r;
        			ans += freq[m] * freq[k];
        		}
        	}
        }
        for(auto x: freq){
        	if(x.second >= 4){
        		int t = x.second;
        		int temp = 1;
        		REP(i,4){
        			temp*= (t-i);
        		}
        		temp /= 24;
        		ans += temp;
        	}
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}



