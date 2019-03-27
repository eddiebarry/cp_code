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

ll mod(ll a){
    return a<0?-a:a;
}


/********** Main()  function **********/
int main()
{
    
    
    ll n = SI();
    VI a,b;
    multiset<ll>A,B;
    REP(i,n){
        ll x = SI();
        a.PB(x);
        A.insert(x);
    }
    REP(i,n){
        ll x = SI();
        b.PB(x);
        B.insert(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans= 0;


    REP(i,n){
        ll x = a[n - 1 -i];
        // ll y = b[i];
        B.insert(x);
        auto it = B.lower_bound(x);
        auto succ = it;
        auto pre = it;
        bool pre_exists = false, post_exists = false;
        if(it!=B.begin()){
            pre_exists = true;
            --pre;
        }
        ++it;
        if(it!=B.end()){
            post_exists = true;
            --it;
            ++succ;
        }
        ll pr = 0, suc = 0;
        if(pre_exists && post_exists){
            pr = *pre;
            suc = *succ;
            // cout<<pr<<" "<<suc<<"\n";
            if(mod(pr - x ) < mod(suc - x)){
                B.erase(B.find(pr));
                ans += mod(pr - x );
            }
            else{
                B.erase(B.find(suc));
                ans += mod(suc - x );
            }

        }
        else if(pre_exists){
            pr = *pre;
            B.erase(pre);
            ans += mod(pr - x );
        }
        else if(post_exists){
            suc = *succ;
            B.erase(succ);
            ans += mod(suc - x );
        }

        B.erase(B.find(x));
        
        // ans += mod(y-x);
    }
    cout<<ans%MOD<<"\n";
    return 0;
}



