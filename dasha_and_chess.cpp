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

#include <unordered_set>
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



/********** Main()  function **********/
int main()
{
    VII rooks;
    unordered_multiset <ll> col;
    unordered_multiset <ll> row;

    ll k_x = SI(), k_y = SI();
    
    ll x = 666;
    while(x--){
        ll a = SI(), b = SI();
        rooks.push_back(MP(a,b));
        row.insert(a);
        col.insert(b);
    }
    col.insert(0);
    col.insert(999);
    row.insert(0);
    row.insert(999);
    
    x = 1000;
    while(x--){
        ll max_steps= -1;

        ll h_x =k_x, h_y = k_y;
        //check_up
        ll dir = 1; 
        ll temp_steps = 0;
        ll a_x = -1, a_y = -1;
        while(row.find(h_x+1)==row.end()&&col.find(h_y)==col.end()){
            temp_steps++;
            h_x++;
        }
        if(max_steps<temp_steps){
            max_steps = temp_steps;
            dir = 1;
            a_x = k_x+1;
            a_y = k_y;
        }

        temp_steps = 0;
        h_x =k_x, h_y = k_y;
        while(row.find(h_x-1)==row.end()&&col.find(h_y)==col.end()){
            temp_steps++;
            h_x--;
        }
        if(max_steps<temp_steps){
            max_steps = temp_steps;
            dir = 2;
            a_x = k_x-1;
            a_y = k_y;
        }
        h_x =k_x, h_y = k_y;
        temp_steps = 0;
        while(row.find(h_x+1)==row.end()&&col.find(h_y+1)==col.end()){
            temp_steps++;
            h_x++;
            h_y++;
        }
        if(max_steps<temp_steps){
            max_steps = temp_steps;
            dir = 3;
            a_x = k_x+1;
            a_y = k_y+1;
        }
        temp_steps = 0;
        h_x =k_x, h_y = k_y;
        while(row.find(h_x-1)==row.end()&&col.find(h_y-1)==col.end()){
            temp_steps++;
            h_x--;
            h_y--;
        }
        if(max_steps<temp_steps){
            max_steps = temp_steps;
            dir = 4;
            a_x = k_x-1;
            a_y = k_y-1;
        }
        temp_steps = 0;
        h_x =k_x, h_y = k_y;
        while(row.find(h_x)==row.end()&&col.find(h_y+1)==col.end()){
            temp_steps++;
            h_y++;
        }
        if(max_steps<temp_steps){
            max_steps = temp_steps;
            dir = 5;
            a_x = k_x;
            a_y = k_y+1;
        }
        temp_steps = 0;
        h_x =k_x, h_y = k_y;
        while(row.find(h_x)==row.end()&&col.find(h_y-1)==col.end()){
            temp_steps++;
            h_y--;
        }
        if(max_steps<temp_steps){
            max_steps = temp_steps;
            dir = 6;
            a_x = k_x;
            a_y = k_y-1;
        }
        temp_steps = 0;
        h_x =k_x, h_y = k_y;
        while(row.find(h_x-1)==row.end()&&col.find(h_y+1)==col.end()){
            temp_steps++;
            h_y++;
            h_x--;
        }
        if(max_steps<temp_steps){
            max_steps = temp_steps;
            dir = 7;
            a_x = k_x-1;
            a_y = k_y+1;
        }
        temp_steps = 0;
        h_x =k_x, h_y = k_y;
        while(row.find(h_x+1)==row.end()&&col.find(h_y-1)==col.end()){
            temp_steps++;
            h_y--;
            h_x++;
        }
        if(max_steps<temp_steps){
            max_steps = temp_steps;
            dir = 8;
            a_x = k_x+1;
            a_y = k_y-1;
        }

        cout<<a_x<<" lololol  "<<a_y<<endl;
        cout.flush();
        ll k = SI(), d = SI(), y = SI();
        k_x = a_x;
        k_y = a_y;
        row.erase(row.find(rooks[k-1].first));
        col.erase(col.find(rooks[k-1].second));

        rooks[k-1].first = d;
        rooks[k-1].second = y;

    }




    return 0;
}



