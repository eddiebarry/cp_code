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






/********** Main()  function **********/
int main()
{
    ll n = SI(), M = SI();
    VI num(n,0);
    VI cost(n,0);
    multiset<PII>dishes;
    REP(i,n){
        num[i]=SI();
    }
    REP(i,n){
        cost[i]=SI();
        dishes.insert(make_pair(cost[i], i ));
    }
    int ord[n];
    int i = 0;
    for(auto x : dishes){
        ord[i] = x.second;
        i++;
    }


    ll curr = 0;
    REP(i,M){
        ll x = SI(), m = SI();
        x--;
        if(num[x]>= m){
            cout<<m*cost[x]<<"\n";
            num[x]-=m;
        }
        else{
            ll ans = 0;
            ans += num[x]*cost[x];
            m -= num[x];
            num[x]=0;
            while(m>0){
                if(curr >= n){
                    break;
                }
                if(num[ord[curr]] > m){
                    ans += m * cost[ord[curr]];
                    num[ord[curr]] -= m;
                    m = 0;
                }
                else{
                    ans += num[ord[curr]] * cost[ord[curr]];
                    m   -= num[ord[curr]];
                    num[ord[curr]]=0;
                    curr++;
                }
            }
            if(m > 0){
                ans = 0;
            }
            cout<<ans<<"\n";
        }

    }



    return 0;
}



