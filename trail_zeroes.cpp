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



ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  

bool miillerTest(ll d, ll n) 
{ 
    // Pick a random number in [2..n-2] 
    // Corner cases make sure that n > 4 
    ll a = 2 + rand() % (n - 4); 

  
    // Compute a^d % n 
    ll x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 
  
    // Keep squaring x while one of the following doesn't 
    // happen 
    // (i)   d does not reach n-1 
    // (ii)  (x^2) % n is not 1 
    // (iii) (x^2) % n is not n-1 
    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
  
    // Return composite 
    return false; 
} 
  
// It returns false if n is composite and returns true if n 
// is probably prime.  k is an input parameter that determines 
// accuracy level. Higher value of k indicates more accuracy. 
bool isPrime(ll n, ll k = 40) 
{ 
    // Corner cases 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
  
    // Find r such that n = 2^d * r + 1 for some r >= 1 
    ll d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
  
    // Iterate given nber of 'k' times 
    for (int i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
  
    return true; 
} 

bool check_fact(ll n){
    for(int i = 2; i *i <= n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


ll return_ans(ll p, ll r, ll n){
    ll sum = 0;
    ll temp = n;
    while(temp > 0){
        sum+= temp%p;
        temp/=p;
    }

    ll ans = n - sum;
    ans /= (p-1);
    return ans / r;
}




ll find_ans(ll n, ll b) 
{ 
    // Print the number of 2s that divide n 
    ll min = MOD;
    ll cand;
                ll r = 0;
    ll num = b;

    if(n%2==0){


    while (n%2 == 0) 
    { 
        // printf("%d ", 2); 
        n = n/2; 
        r++;
    } 
    cand = return_ans(2,r,num);
    if(cand<min){
        min = cand;
    }
    }


    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 


    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        if(n%i==0){
                    r = 0;
        while (n%i == 0) 
        { 
            // printf("%d ", i); 
            n = n/i; 
            r++;
        } 
        ll cand = return_ans(i,r,num);
        if(cand<min){
            min = cand;
        }
        }
    } 

  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2){
        ll cand = return_ans(n,1,num);
        if(cand<min){
            min = cand;
        }
        // printf ("%d ", n); 
    }
    return min;
} 







/********** Main()  function **********/
int main()
{
    ll n = SI(), b = SI();

    cout<<find_ans(b,n);



    return 0;
}



