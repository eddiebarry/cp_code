/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Edgar Monis
 * Handle: the_kng_in_the_!~th
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

/*******  All   Required define Pre-Processors and typedef Constants *******/
#define FOR(i, j, k, in) for (ll  i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (ll  i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all  (cont) cont.begin(), cont.end()
#define rall  (cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define read(type) readll <type>()
#define ll  long long
typedef pair< ll  , ll  > PII;
typedef vector<ll  > VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<ll  ,ll  > MPII;
typedef set<ll  > SETI;
typedef multiset<ll  > MSETI;



ll  SI() 
{ 
    ll x;
    cin>>x;
    return x;
} 

ll scr[5000+10];
ll an[5000+10];
ll how_much[10000+20];

/********** Main()  function **********/
int  main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll   t  = SI();
    while(t--){
        ll   c = SI(), m = SI(), r = SI(), k = SI();
        // if(m==1){
        //     cout<<1<<" "<<r*m<<"\n";
        //     REP(i,r){
        //         ll   p = SI(), c = SI();
        //     }
        //     continue;
        // }
        
        REP(i,5010){
            scr[i]=0;
            an[i]=0;
            how_much[i]=0;
            how_much[5010+i]=0;
        }
        REP(i,r){
            ll   p = SI(), c = SI();
            c--;
            p--;
            // cout<<"\noriginal pos is "<<p<<"\n";
            c%= (k+m-1);
            ll   sc = c < k ? m  : c - k  + 1;
            ll go_back = p + sc;
            go_back%=m;
            p = go_back;
            // // ll   go_back = m - sc ;
            // // go_back%=m;
            // // p -= go_back;
            // // p %=m;

            // while(p<0){
            //     p+=m;
            // }
            // cout<<"\nc is "<<sc<<" position of m is "<<p<<"\n";
            scr[p]+=m;
        }

        ll  num_add =0, curr_to_add=0, last_add=0;
        // set<ll  >idx_to_remove;
        // map<ll  ,ll  >how_much;
        // cout<<"\n scr arr is \n";
        // REP(i,m){
        //     cout<<scr[i]<<" ";
        // }
        // cout<<"\n";

        for(ll  i = 0, j = m; i < j ; i++){
            ll   curr_idx = i%m;
            num_add -= how_much[i];
            
            

            if(scr[curr_idx]>0){
                
                num_add+= scr[curr_idx]/m;
                how_much[i+m] = scr[curr_idx]/m;

                curr_to_add +=scr[curr_idx];
                scr[curr_idx]=0;

                j+=curr_idx-last_add;
                last_add = curr_idx;
            }
            // cout<<"i is "<<i<<" curr_idx is"<<curr_idx<<" num_to_remove is "<<num_add<<" curr_to_add is "<<curr_to_add<<"\n"; 
            an[curr_idx]+=curr_to_add;
            curr_to_add -= num_add;
        }
        // cout<<"final array is \n";
        // REP(i,m){
        //     cout<<an[i]<<" ";
        // }
        // cout<<"\n";
        // cout<<"\**********************\n";
        ll   max = -1;
        ll   ans = -1;
        REP(i,m){
            if(an[i]>max){
                max = an[i];
                ans = i;
            }
        }
        cout<<ans+1<<" "<<max<<endl;

    }    
    

    return 0;
}




