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

bool chk(string &s){
    return (s.size()==7 && s[0] == 'k' && s[1] == 'e' && s[2] == 'y' && s[3] == 'e'&& s[4] == 'n' && s[5] == 'c' && s[6] == 'e' );
}


/********** Main()  function **********/
int main()
{
    
    ll n = SI();
    VI a(n);
    VI b(n);
    VI diff(n,0);
    ll sum_a= 0, sum_b = 0;
    REP(i,n){
        a[i]=SI();
        sum_a += a[i];
    }
    REP(i,n){
        b[i]=SI();
        sum_b += b[i];
    }
    if(sum_a < sum_b){
        cout<<-1;
    }
    else{
        std::vector<ll> diff(n);
        REP(i,n){
            diff[i]=a[i]-b[i];
        }
        sort(diff.begin(),diff.end());
        ll summ_neg = 0;
        ll num_affect = 0;
        REP(i,n){
            if(diff[i]<0){
                num_affect++;
                summ_neg -= diff[i];
            }
            else{
                break;
            }
        }
        REP(i,n){
            if(summ_neg>0){
                num_affect++;
                summ_neg-=diff[n-1-i];
            }
            else{
                break;
            }
        }
        cout<<num_affect;
    }






    return 0;
}

        // set<PII> s;
        // REP(i,n){
        //     s.insert(MP(a[i]-b[i],i));
        // }
        // std::vector<bool > touch(n,false);
        // auto it = s.begin();
        // PII pr = *it;
        // ll smll = pr.first;
        // ll idx = pr.second;
        // while(smll<0){
        //     touch[idx]=true;
        //     //find largest element
        //     auto itr = s.rbegin();
        //     PII te = *it;
        //     ll larg = te.first;
        //     ll larg_idx = te.second;
        //     touch[larg_idx] = true;
        //     //keep giving untill it becomes 0
        //     while(larg>0){
        //         //find smallest,
                

        //     }
        // }


