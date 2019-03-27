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
	ll n = SI(), k = SI();
    // ll past = -1;
    VI scores(n,0);
    ll ans =0;
    REP(i,n){
        scores[i]=SI();
        ans += scores[i];
    }
    // cout<<"ans is "<<ans<<"\n";
    std::vector<char> chars;
    REP(i,n){
        char x;
        cin>>x;
        chars.push_back(x);
    }
    char past = 'A';

    ll curr_num = 1;
    FOR(i, 0, n, 1){
        if(chars[i]==past){
            curr_num++;
        }
        else{
            curr_num = 1;
        }
        if(curr_num==k){
            past = chars[i];
            multiset<ll>best;
            REP(j,k){
                ans-=scores[i-j];
                best.insert(scores[i-j]);
                // cout<<scores[i-j]<<" is inserted in set\n";
            }
            FOR(j,i+1,n,1){
                if(chars[j]==past){
                    ans-=scores[j];
                    best.insert(scores[j]);
                    // cout<<scores[j]<<" is inserted in set\n"<<endl;
                }
                else{
                    i = j-1;
                    curr_num = 1;
                    break;
                }
            }
            REP(i,k){
                auto it = best.rbegin();
                ll max = *it;
                ans+=max;
                best.erase(best.find(max));
            }
        }
        past = chars[i];
    }
    cout<<ans<<"\n";

    // REP(i,100){
    // 	cout<<i<<" "<<dig_root(i)<<"\n";
    // }
    return 0;
}


    // REP(i,n){
    //     char c;
    //     cin>>c;
    //     chars.push_back(c);
    //     if(c==past){
    //         curr_num++;
    //         ans+=v[i];
    //     }
    //     else{
    //         past = c;
    //         curr_num = 1;
    //         ans+=v[i];
    //     }
    //     if(curr_num==k){
    //         //add past k
    //         multiset<ll> num_to_remove;
    //         REP(j,k){
    //             num_to_remove.insert(v[i-j]);
    //             ans -= v[i-j]
    //         }
    //         i++;
    //         cin>>c;
    //         chars.push_back(c);
    //         ans+=v[i];
    //         while(c==past){
    //             ans-=v[i];
    //             i++;
    //             cin>>c;
    //             chars.push_back(c);
    //             ans+=v[i];
    //         }
    //     }
    // // }
