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

/********** Main()  function **********/
int main()
{
    int n = SI(), m = SI();

    VI a(n);
    VI b(n);
    MPII mp;
    REP(i,n){
        a[i]=SI();
        mp[a[i]]++;
        if(mp[a[i]] > 1 ){
            cout<<0;
            return 0;
        }
    }
    REP(i,m){
        b[i]=SI();
        mp[b[i]]++;
        if(mp[b[i]] > 2 ){
            cout<<0;
            return 0;
        }
    }
    
    std::vector<bool> marked(n*m,false);
    ll arr[n][m];
    std::vector<ll> places(n*m,0);
    REP(i,n){
        REP(j,m){
            ll max_poss = min(a[i],b[j]);
            places[max_poss-1]++;
            if(a[i]==b[j]){
                arr[i][j] = a[i];
                if(marked[a[i]-1]){
                    cout<<0;
                    return 0;
                }
                marked[a[i]-1] = true;
                places[a[i]-1]--;
            }
            else{
                arr[i][j]=-1;
            }
        }
    }
    // std::vector<ll> places(n*m,0);
    //find largest not entered numbe;
    ll curr_num = -1;
    REP(i,n*m){
        if(!marked[n*m-1-i]){
            curr_num = n*m-i;
            break;
        }
    }
    //find summ of all elements greater than 
    ll sum_places = 0;
    FOR(i,curr_num - 1, n*m ,1){
        sum_places+=places[i];
    }
    ll ans = 1;
    ll flag = true;
    RFOR(i,curr_num-1,0,1){
        sum_places += places[i];
        if(flag){
            sum_places -= places[i];
            flag = false; 
        }
        if(!marked[i]){
            ans *= sum_places;
            ans %= MOD;
            sum_places--;

        }
        // cout<<i+1 <<" "<<sum_places<<" \n";
    }
    cout<<ans;

    return 0;
}



