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
    //all unique
    ll col_freq[3][3];
    REP(i,3){
    	REP(j,3){
    		col_freq[i][j]=0;
    	}
    }

    REP(i,s.size()){
    	ll x = i % 3;
    	ll col;
    	if(s[i]=='R'){
    		col = 0;
    	}
    	else if(s[i]=='G'){
    		col = 1;
    	}
    	else{
    		col = 2;
    	}
    	col_freq[x][col]++;
    }
    //pick_max;
    ll max_row;
    ll ma = 0;
    ll row = -1;
    REP(i,3){
    	REP(j,3){
    		if(col_freq[i][j]>ma){
    			ma = col_freq[i][j];
    			row = j;
    			max_row = i;
    		}
    	}
    }
    ma = row;
    ll sec_max;
    ll ma1=0;
    row = -1;
    REP(i,3){
    	if(i==max_row){
    		continue;
    	}
    	REP(j,3){
    		if(j==ma){
    			continue;
    		}

    		if(col_freq[i][j]>ma1){
    			ma1 = col_freq[i][j];
    			row = j;
    			sec_max = i;
    		}
    	}
    }
    ma1 = row;
    sec_max++;
    max_row++;
    ma++;
    ma1++;
    ll last = 6 - sec_max - max_row;
    ll last_letter = 6 - ma - ma1;
    // cout<<max_row<<" "<<sec_max<<" "<<last<<"\n"<<ma<<" "<<ma1<<" "<<last_letter<<"\n";

    ll changes = 0;
    string final_string ="";
    REP(i,s.size()){
    	ll temp;
    		if(s[i]=='R'){
    			temp = 1;
    		}
    		if(s[i]=='G'){
    			temp = 2;
    		}
    		if(s[i]=='B'){
    			temp = 3;
    		}
    	if(i%3 +1 ==  max_row){
    		if(temp!=ma){
    			changes++;
    		}
    		if(ma == 1){
    			final_string+="R";
    		}
    		else if(ma == 2){
    			final_string+="G";
    		}
    		else{
    			final_string+="B";
    		}
    	}
    	else if(i%3 +1 ==  sec_max){
    		if(temp!=ma1){
    			changes++;
    		}
    		if(ma1 == 1){
    			final_string+="R";
    		}
    		else if(ma1 == 2){
    			final_string+="G";
    		}
    		else{
    			final_string+="B";
    		}
    	}
    	else{
    		if(temp!=last_letter){
    			changes++;
    		}
    		if(last_letter == 1){
    			final_string+="R";
    		}
    		else if(last_letter == 2){
    			final_string+="G";
    		}
    		else{
    			final_string+="B";
    		}
    	}

    }
    cout<<changes<<"\n"<<final_string;


    return 0;
}



