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
#define ROW 400
#define COL 400  

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
 
  


long long  kadane(long long * arr, long long * start, 
           long long * finish, long long  n)  
{  
 
    long long  sum = 0, maxSum =  LONG_LONG_MIN, i;  
  
  
    *finish = -1;  
  
  
    long long  local_start = 0;  
  
    for (i = 0; i < n; ++i)  
    {  
        sum += arr[i];  
        if (sum < 0)  
        {  
            sum = 0;  
            local_start = i + 1;  
        }  
        else if (sum > maxSum)  
        {  
            maxSum = sum;  
            *start = local_start;  
            *finish = i;  
        }  
    }  

    if (*finish != -1)  
        return maxSum;  

    maxSum = arr[0];  
    *start = *finish = 0;  
  
    for (i = 1; i < n; i++)  
    {  
        if (arr[i] > maxSum)  
        {  
            maxSum = arr[i];  
            *start = *finish = i;  
        }  
    }  
    return maxSum;  
}  
 
void findMaxSum(long long  M[][COL])  
{  
    // Variables to store the final output  
    long long  maxSum =  LONG_LONG_MIN, finalLeft, finalRight,  
                          finalTop, finalBottom;  
  
    long long  left, right, i;  
    long long  temp[ROW], sum, start, finish;  
  

    for (left = 0; left < COL; ++left)  
    {  

        memset(temp, 0, sizeof(temp));  

        for (right = left; right < COL; ++right)  
        {  
              
            // Calculate sum between current left  
            // and right for every row 'i'  
            for (i = 0; i < ROW; ++i)  
                temp[i] += M[i][right];    
            sum = kadane(temp, &start, &finish, ROW);  
  
            if (sum > maxSum)  
            {  
                maxSum = sum;  
                finalLeft = left;  
                finalRight = right;  
                finalTop = start;  
                finalBottom = finish;  
            }  
        }  
    }  
  
    cout << maxSum << endl;  
}  
  
// Driver Code 
int  main()  
{  
    long long  M[ROW][COL];

    for(int i = 0; i < ROW ; i++){
    	for(int j  = 0; j < COL; j++){
    		M[i][j] = -MOD;
    	}
    }
    ll n = SI(), m = SI();
    REP(i,n){
    	REP(j,m){
    		M[i][j]=SI();
    	}
    } 
  
    findMaxSum(M);  
  
    return 0;  
}  