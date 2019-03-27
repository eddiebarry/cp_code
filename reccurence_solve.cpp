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


ll ans(ll t0, ll t1, ll t2, ll n){
    ll arr[5][5];
    REP(i,5){
        REP(j,5){
            arr[i][j]=0;
        }
    }
    arr[0][0]=1;
    arr[0][2]=3;
    arr[0][3]=2;
    arr[0][4]=-1;
    arr[1][0]=1;
    arr[2][1]=1;
    arr[3][3]=2;
    arr[3][4]=-1;
    arr[4][3]=1;

    ll a[5][5];
    REP(i,5){
        REP(j,5){
            a[i][j]=0;
            if(i==j){
                a[i][j]=1;
            }
        }
    }

    while(n > 0){
        // cout<<n<<" is n\n";
        ll mul[5][5];
        if(n%2==1){
            //multiply a by arr
            // ll mul[5][5];
            REP(i,5){
                REP(j,5){
                    mul[i][j]=0;
                    REP(z,5){
                        mul[i][j] += (a[i][z]*arr[z][j])%MOD;
                        // while(mul[i][j]<0){
                        //     mul[i][j]+=MOD;
                        // }
                        mul[i][j] %= MOD;
                    }
                }
            }
            REP(i,5){
                REP(j,5){
                    a[i][j]=mul[i][j];
                }
            }
            // REP(i,5){
            //     REP(j,5){
            //         cout<<a[i][j]<<" ";
            //     }
            //     cout<<"\n";
            // }

        }

            REP(i,5){
                REP(j,5){
                    mul[i][j]=0;
                    REP(z,5){
                        mul[i][j] += (arr[i][z]*arr[z][j])%MOD;
                        // while(mul[i][j]<0){
                        //     mul[i][j]+=MOD;
                        // }
                        mul[i][j] %= MOD;
                    }
                }
            }
            REP(i,5){
                REP(j,5){
                    arr[i][j]=mul[i][j];
                }
            }
        n/=2;
    }
    ll ans = (a[0][0]*t2)%MOD;
    ans += (a[0][1]*t1)%MOD;
    ans %= MOD;
    ans += (a[0][2]*t0)%MOD;
    ans %= MOD;
    ans += (a[0][3]*4)%MOD;
    ans %= MOD;
    ans += (a[0][4]*(2))%MOD;
    ans %= MOD;
    while(ans <0){
        ans+=MOD;
    }

    return ans;


}


/********** Main()  function **********/
int main()
{
    
    
    ll t = SI();
    while(t--){
        ll a = SI(), b = SI(), c = SI(), n = SI();

        cout<<ans(a,b,c,n-2)<<"\n";
    }
    return 0;
}

        // b -=2;
        // c -=6;
        // while(b<0){
        //     b+=MOD;
        // }
        // while(c<0){
        //     c+=MOD;
        // }
        // a += d;
        // a%=MOD;
        // b +=d;
        // b%=MOD;
        // c+=d;
        // c&=MOD;
        // b+=m_3;
        // c+=2*m_3;
        // b%=MOD;
        // c%=MOD;
        // cout<<a<<" "<<b<<" "<<c<<"\n";
        // while(a<0){
        //     a+=MOD;
        // }
        // while(b<0){
        //     b+=MOD;
        // }
        // while(c<0){
        //     c+=MOD;
        // }
        // VI v;
        // REP(i,3){
        //     v.push_back(SI());
        // }
        // ll n = SI();
        // REP(i,n-2){
        //     ll x = (((3 * v[i+3 - 3])%MOD + 2*(i+3)%MOD)%MOD + v[i+3-1])%MOD;
        //     v.push_back(x);
        // }
        // cout<<v[n]<<"\n";


