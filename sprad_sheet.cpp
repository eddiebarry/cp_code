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

#include <ctype.h>
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
    ll n = SI();
    while(n--){
    	string s;
    	cin>>s;
    	bool letter = false, number = false;
    	bool type_1 = false;
    	REP(i,s.size()){
    		// cout<<isalpha(s[i])<<"\n";
    		// cout<<isalpha(s[i])<<" "<<s[i]<<"\n";
    		// cout<<letter<<" "<<number<<" "<<type_1<<"\n ";
    		if(isalpha(s[i]) && !letter){
    			letter = true;
    			continue;
    		}
    		if(!isalpha(s[i]) && letter){
    			number = true;
    			continue;
    		}
    		if(number && isalpha(s[i])){
    			type_1 = true;
    			continue;
    		}

    	}
    	// if(!type_1){
    	// 	cout<<"string is not type 1\n";
    	// }
    	if(type_1){
    		string row = "";
    		ll sec_idx = -1;
    		REP(i,s.size()){
    			if(isalpha(s[i+1])){
    				sec_idx = i+2;
    				break;
    			}
    			// row *= 10;
    			row += s[i+1]-'0';
    		}
    		// cout<<"sec idx is"<<sec_idx<<"\n";
    		ll col = 0;
    		FOR(i,sec_idx,s.size(),1){
    			col*=10;
    			col+= s[i]-'0';
    		}
    		// cout<<row<<" "<<col<<"\n";
    		string ans ="";
    		while(col > 0){
    			ans = char(col%(26) + 'A' -1) + ans;
    			col/=26;
    		}
    		cout<<ans<<row<<"\n";
    	}
    	else{
    		ll row = 0,col = 0;
    		ll sec_idx = -1;
    		REP(i,s.size()){
    			if(isalpha(s[i])){
    				row*=('z'-'a'+1);
    				row+=s[i]-'A'+1;
    			}
    			else{
    				col*=10;
    				col+=s[i]-'0';
    			}
    		}
    		cout<<"R"<<col<<"C"<<row<<"\n";
    	}
    }
    return 0;
}



