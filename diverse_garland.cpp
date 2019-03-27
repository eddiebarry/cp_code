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
	ll GHs = SI();
    string s;
    cin>>s;
    ll last = 'R';
    ll changes = 0;
    bool first = true;

    string ans ="";
    REP(i,s.size()){
        if(i==s.size()){
            ans+=s[i];
            break;
        }
        if(s[i]==s[i+1]){
            ll x = s[i];
            ll num = 0;
            FOR(j, i, s.size(), 1){
                if(s[j]==s[i]){
                    num++;
                }
                else{
                    if(first){
                        last = s[j];
                        first = false;
                    }
                    break;
                }
            }
            
            changes+=num/2;
            if(num%2==0){
                char c = 'R' + 'G' + 'B' - last - s[i];
                REP(j,num){
                    if(j%2==0){
                        ans+=c;    
                    }
                    else{
                        ans+=s[i];
                    }
                    
                }
                last=s[i];
            }
            else{
                REP(j,num){
                    char c = 'R' + 'G' + 'B' - last - s[i];
                    if(j%2==0){
                        ans+=s[i];
                    }
                    else{
                        ans+=c;
                    }
                    
                }
                last=s[i];
            }
            i+=num-1;
        }
        else{
            ans+=s[i];
            last = s[i];
        }
    }
    cout<<changes<<"\n"<<ans<<"\n";

    return 0;
}



