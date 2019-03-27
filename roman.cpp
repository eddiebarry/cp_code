/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Denzil Bernard  
 * Handle: 1_mn_RMY
 *
 */
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

ll min(ll a, ll b){
    return a< b? a:b;
}
ll max(ll a, ll b){
    return a>b? a:b;
}

ll k;

ll elim_n_cnt(VI v, ll i){
    // for(auto x : v){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";

    ll n = v.size();
    FOR(x,i,n,k){
        v[x]=0;
    }
    //     for(auto x : v){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    ll a = 0, b = 0;
    REP(i,n){
        if(v[i]==-1){
            a++;
        }
        else if (v[i]==1){
            b++;
        }
    }
    return max(a,b) - min(a,b);
}


/********** Main()  function **********/
int main()
{
    int n = SI();
    k = SI();
    VI v(n);
    REP(i,n){
        v[i]=SI();
    }
    ll max = -1;
    REP(i,k){
        ll z = elim_n_cnt(v,i);
        if(z>max){
            max = z;
        }
    }
    cout<<max;


    return 0;
}



