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


ll mod(ll a){
	return a<0?-a:a;
}


// string xyz(string &s, set<string>&notes ){
// 	std::vector<bool> seen(26,false);
// 	std::vector<int> first(26,-1);
// 	std::vector<int> last(26,-1);

// 	ll idx = 0;
// 	for(auto x : s){
// 		if(!seen[x-'a']){
// 			seen[x-'a'] = true;
// 			first[x-'a'] = idx;
// 		}

// 		last[x-'a']=idx;

// 		idx++;
// 	}

// 	ll num = -1;
		
// 	ll largest = 0;

// 	REP(i,26){
// 		ll diff = last[i] - first[i];
// 		if(diff>=largest && seen[i]){
// 			largest = diff;
// 			num = i;
// 		}
// 	}

// 	if(num==-1){
// 		return "1";
// 	}

// 	string note = "";
// 	for(int i = first[num]; i <= last[num]; i++){
// 		note += s[i];
// 	}
// 	notes.insert(note);
// 	// cout<<note<<"\n";


// 	string temp = "";
// 	for(int i = 0 ; i < first[num]; i++){
// 		temp += s[i];
// 	}

// 	for(int i = last[num]+1 ; i < s.size(); i++){
// 		temp += s[i];
// 	}

// 	return temp;
// }


/********** Main()  function **********/
int main()
{
	string a, b;
	cin>>a>>b;

	set<string>notes;

	int arr[a.size()];
	int brr[b.size()];

	REP(i,a.size()- 1){
		int j = i + 1;
		if(a[j] == a[j-1]){
			arr[j]=1;
			arr[j-1]=1;
		}
		else{
			arr[j]=2;
		}
	}

	REP(i,a.size()){
		if(arr[i]==2){
			string x = "" ;
			x+=a[i];
			notes.insert(x);
		}
		else{
			string x ="";
			x+=a[i];
			while(a[++i]==x[0]){
				x+=a[i];
			}
			notes.insert(x);
			--i;
		}
	}


	REP(i,b.size()- 1){
		int j = i + 1;
		if(b[j] == b[j-1]){
			brr[j]=1;
			brr[j-1]=1;
		}
		else{
			brr[j]=2;
		}
	}

	REP(i,b.size()){
		if(brr[i]==2){
			string x = "" ;
			x+=b[i];
			notes.insert(x);
		}
		else{
			string x ="";
			x+=b[i];
			while(b[++i]==x[0]){
				x+=b[i];
			}
			notes.insert(x);
			--i;
		}
	}

	cout<<notes.size();

    
    return 0;
}



