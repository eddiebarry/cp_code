/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Denzil Bernard  
 * Handle: 1_mn_RMY
 *
 */
// #include <bits/stdc++.h>
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

int cost[2048+10][2048+10];
int DP[2048+10][32+10];
ll sz;

ll dp(ll idx, ll k){
	return 0;
	// ll num_left = sz - idx;
	// cout<<"calling dp of "<<idx<<" "<<k<<endl;

	if(DP[idx][k]!=-1){
		// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<DP[idx][k]<<endl;
		return DP[idx][k];
	}
	else{
		if(k==0){
			DP[idx][k] = cost[idx][sz-1];
			// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<DP[idx][k]<<endl;
			return DP[idx][k];
		}
		else{
			ll min = MOD;
			FOR(i, idx+ 1, sz, 1){
				ll te = dp(i,k-1) + cost[idx][i-1];
				if(te < min){
					min = te;
				} 
			}
			DP[idx][k] = min;
			// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<min<<endl;
			return DP[idx][k];
		}
	}
}


// ll dp(ll idx , ll k){
//     REP(i,sz){
//         DP[i][0]=cost[i][sz-1];
//     }
//     FOR(z,1,k+1,1){
//     	REP(i,sz-1){
// 	        ll working_idx = sz - 2 - i;
// 	        cout<<"\nworking_idx is "<<working_idx<<" k is "<<k<<endl;
// 	        ll min = MOD;
// 	        FOR(j,working_idx+1,sz,1){
// 	        	ll te = DP[j][z-1] + cost[working_idx][j-1];
// 	        	if(te < min){
// 	        		min = te;
// 	        	}
// 	        }
// 	        DP[working_idx][z]=min;
// 	        cout<<"DP is "<<min<<endl;
// 	        REP(i,k+1){
// 		    	REP(j,sz+1){
// 		    		cout<<DP[j][i]<<" ";
// 		    	}
// 		    	cout<<endl;
// 		    }
// 	    }
//     }
//     return DP[0][k];
// }


/********** Main()  function **********/
int main()
{
    
    
    string s;
    cin>>s;
    sz = s.size();
    ll k = SI();

    cout<<k<<" "<<sz<<"\n";
    REP(i,2048+1){
    	REP(j,2048+1){
    		cost[i][j]=-1;
    	}
    	REP(j,32+1){
    		DP[i][j]=-1;
    		if(i==sz-1){
    			DP[i][j]=0;
    		}
    	}
    }
    


    REP(i,sz){
    	VI co('z'-'a',0);
    	FOR(j,i,sz,1){
    		ll min = MOD;
    		REP(z,26){
    			ll te =  (z - (s[j] - 'a'))%26;
    			if(te < 0){
    				te +=26;
    			}
    			co[z]+=te;
    			if(min > co[z]){
    				min = co[z];
    			}
    		}
    		cost[i][j]=min;
    	}
    }
    // REP(i,sz){
    // 	REP(j,sz){
    // 		cout<<cost[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }


    cout<<dp(0,k)<<endl;



    return 0;
}




// /*
//  * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
//  *       Example:-   $ g++ -std=c++11 c++Template.cpp
//  *
//  * Author : Denzil Bernard  
//  * Handle: 1_mn_RMY
//  *
//  */
// // #include <bits/stdc++.h>
// // C
// #ifndef _GLIBCXX_NO_ASSERT
// #include <cassert>
// #endif
// #include <cctype>
// #include <cerrno>
// #include <cfloat>
// #include <ciso646>
// #include <climits>
// #include <clocale>
// #include <cmath>
// #include <csetjmp>
// #include <csignal>
// #include <cstdarg>
// #include <cstddef>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>

// #if __cplusplus >= 201103L
// #include <ccomplex>
// #include <cfenv>
// #include <cinttypes>
// //#include <cstdalign>
// #include <cstdbool>
// #include <cstdint>
// #include <ctgmath>
// #include <cwchar>
// #include <cwctype>
// #endif

// // C++
// #include <algorithm>
// #include <bitset>
// #include <complex>
// #include <deque>
// #include <exception>
// #include <fstream>
// #include <functional>
// #include <iomanip>
// #include <ios>
// #include <iosfwd>
// #include <iostream>
// #include <istream>
// #include <iterator>
// #include <limits>
// #include <list>
// #include <locale>
// #include <map>
// #include <memory>
// #include <new>
// #include <numeric>
// #include <ostream>
// #include <queue>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <stdexcept>
// #include <streambuf>
// #include <string>
// #include <typeinfo>
// #include <utility>
// #include <valarray>
// #include <vector>

// #if __cplusplus >= 201103L
// #include <array>
// #include <atomic>
// #include <chrono>
// #include <condition_variable>
// #include <forward_list>
// #include <future>
// #include <initializer_list>
// #include <mutex>
// #include <random>
// #include <ratio>
// #include <regex>
// #include <scoped_allocator>
// #include <system_error>
// #include <thread>
// #include <tuple>
// #include <typeindex>
// #include <type_traits>
// #include <unordered_map>
// #include <unordered_set>
// #endif

// using namespace std;

// /*******  All Required define Pre-Processors and typedef Constants *******/
// #define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
// #define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
// #define REP(i, j) FOR(i, 0, j, 1)
// #define RREP(i, j) RFOR(i, j, 0, 1)
// #define all(cont) cont.begin(), cont.end()
// #define rall(cont) cont.end(), cont.begin()
// #define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
// #define IN(A, B, C) assert( B <= A && A <= C)
// #define MP make_pair
// #define PB push_back
// #define MOD 1000000007
// #define read(type) readInt<type>()
// #define ll long long
// typedef pair< ll, ll> PII;
// typedef vector<ll> VI;
// typedef vector<PII> VII;
// typedef vector<VI> VVI;
// typedef map<ll,ll> MPII;
// typedef set<ll> SETI;
// typedef multiset<ll> MSETI;

// ll SI(){
//     ll x;
//     cin>>x;
//     return x;
// }

// int cost[2048+1][2048+1];
// int DP[2048+1][32+1];
// ll sz;

// ll dp(ll idx, ll k){
// 	// ll num_left = sz - idx;
// 	// cout<<"calling dp of "<<idx<<" "<<k<<endl;

// 	if(DP[idx][k]!=-1){
// 		// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<DP[idx][k]<<endl;
// 		return DP[idx][k];
// 	}
// 	else{
// 		if(k==0){
// 			DP[idx][k] = cost[idx][sz-1];
// 			// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<DP[idx][k]<<endl;
// 			return DP[idx][k];
// 		}
// 		else{
// 			ll min = MOD;
// 			FOR(i, idx+ 1, sz, 1){
// 				ll te = dp(i,k-1) + cost[idx][i-1];
// 				if(te < min){
// 					min = te;
// 				} 
// 			}
// 			DP[idx][k] = min;
// 			// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<min<<endl;
// 			return DP[idx][k];
// 		}
// 	}
// }



// /********** Main()  function **********/
// int main()
// {
    
    
//     string s;
//     cin>>s;
//     sz = s.size();
//     ll k = SI();
//     REP(i,2048+1){
//     	REP(j,2048+1){
//     		cost[i][j]=-1;
//     	}
//     	REP(j,32+10){
//     		DP[i][j]=-1;
//     		if(i==sz-1){
//     			DP[i][j]=0;
//     		}
//     	}
//     }
    
//     REP(i,sz){
//     	VI co('z'-'a',0);
//     	FOR(j,i,sz,1){
//     		ll min = MOD;
//     		REP(z,26){
//     			ll te =  (z - (s[j] - 'a'))%26;
//     			if(te < 0){
//     				te +=26;
//     			}
//     			co[z]+=te;
//     			if(min > co[z]){
//     				min = co[z];
//     			}
//     		}
//     		cost[i][j]=min;
//     	}
//     }
//     REP(i,sz){
//     	REP(j,sz){
//     		cout<<cost[i][j]<<" ";
//     	}
//     	cout<<endl;
//     }


//     cout<<dp(0,k)<<endl;



//     return 0;
// }




// /*
//  * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
//  *       Example:-   $ g++ -std=c++11 c++Template.cpp
//  *
//  * Author : Denzil Bernard  
//  * Handle: 1_mn_RMY
//  *
//  */
// // #include <bits/stdc++.h>
// // C
// #ifndef _GLIBCXX_NO_ASSERT
// #include <cassert>
// #endif
// #include <cctype>
// #include <cerrno>
// #include <cfloat>
// #include <ciso646>
// #include <climits>
// #include <clocale>
// #include <cmath>
// #include <csetjmp>
// #include <csignal>
// #include <cstdarg>
// #include <cstddef>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>

// #if __cplusplus >= 201103L
// #include <ccomplex>
// #include <cfenv>
// #include <cinttypes>
// //#include <cstdalign>
// #include <cstdbool>
// #include <cstdint>
// #include <ctgmath>
// #include <cwchar>
// #include <cwctype>
// #endif

// // C++
// #include <algorithm>
// #include <bitset>
// #include <complex>
// #include <deque>
// #include <exception>
// #include <fstream>
// #include <functional>
// #include <iomanip>
// #include <ios>
// #include <iosfwd>
// #include <iostream>
// #include <istream>
// #include <iterator>
// #include <limits>
// #include <list>
// #include <locale>
// #include <map>
// #include <memory>
// #include <new>
// #include <numeric>
// #include <ostream>
// #include <queue>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <stdexcept>
// #include <streambuf>
// #include <string>
// #include <typeinfo>
// #include <utility>
// #include <valarray>
// #include <vector>

// #if __cplusplus >= 201103L
// #include <array>
// #include <atomic>
// #include <chrono>
// #include <condition_variable>
// #include <forward_list>
// #include <future>
// #include <initializer_list>
// #include <mutex>
// #include <random>
// #include <ratio>
// #include <regex>
// #include <scoped_allocator>
// #include <system_error>
// #include <thread>
// #include <tuple>
// #include <typeindex>
// #include <type_traits>
// #include <unordered_map>
// #include <unordered_set>
// #endif

// using namespace std;

// /*******  All Required define Pre-Processors and typedef Constants *******/
// #define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
// #define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
// #define REP(i, j) FOR(i, 0, j, 1)
// #define RREP(i, j) RFOR(i, j, 0, 1)
// #define all(cont) cont.begin(), cont.end()
// #define rall(cont) cont.end(), cont.begin()
// #define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
// #define IN(A, B, C) assert( B <= A && A <= C)
// #define MP make_pair
// #define PB push_back
// #define MOD 1000000007
// #define read(type) readInt<type>()
// #define ll long long
// typedef pair< ll, ll> PII;
// typedef vector<ll> VI;
// typedef vector<PII> VII;
// typedef vector<VI> VVI;
// typedef map<ll,ll> MPII;
// typedef set<ll> SETI;
// typedef multiset<ll> MSETI;

// ll SI(){
//     ll x;
//     cin>>x;
//     return x;
// }

// int cost[2048+1][2048+1];
// int DP[2048+1][32+1];
// ll sz;

// ll dp(ll idx, ll k){
// 	// ll num_left = sz - idx;
// 	// cout<<"calling dp of "<<idx<<" "<<k<<endl;

// 	if(DP[idx][k]!=-1){
// 		// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<DP[idx][k]<<endl;
// 		return DP[idx][k];
// 	}
// 	else{
// 		if(k==0){
// 			DP[idx][k] = cost[idx][sz-1];
// 			// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<DP[idx][k]<<endl;
// 			return DP[idx][k];
// 		}
// 		else{
// 			ll min = MOD;
// 			FOR(i, idx+ 1, sz, 1){
// 				ll te = dp(i,k-1) + cost[idx][i-1];
// 				if(te < min){
// 					min = te;
// 				} 
// 			}
// 			DP[idx][k] = min;
// 			// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<min<<endl;
// 			return DP[idx][k];
// 		}
// 	}
// }


// // ll dp(ll idx , ll k){
// //     REP(i,sz){
// //         DP[i][0]=cost[i][sz-1];
// //     }
// //     FOR(z,1,k+1,1){
// //     	REP(i,sz-1){
// // 	        ll working_idx = sz - 2 - i;
// // 	        cout<<"\nworking_idx is "<<working_idx<<" k is "<<k<<endl;
// // 	        ll min = MOD;
// // 	        FOR(j,working_idx+1,sz,1){
// // 	        	ll te = DP[j][z-1] + cost[working_idx][j-1];
// // 	        	if(te < min){
// // 	        		min = te;
// // 	        	}
// // 	        }
// // 	        DP[working_idx][z]=min;
// // 	        cout<<"DP is "<<min<<endl;
// // 	        REP(i,k+1){
// // 		    	REP(j,sz+1){
// // 		    		cout<<DP[j][i]<<" ";
// // 		    	}
// // 		    	cout<<endl;
// // 		    }
// // 	    }
// //     }
// //     return DP[0][k];
// // }


// /********** Main()  function **********/
// int main()
// {
    
    
//     string s;
//     cin>>s;
//     sz = s.size();
//     ll k = SI();

//     cout<<k<<" "<<sz<<"\n";
//     REP(i,2048+1){
//     	REP(j,2048+1){
//     		cost[i][j]=-1;
//     	}
//     	REP(j,32+1){
//     		DP[i][j]=-1;
//     		if(i==sz-1){
//     			DP[i][j]=0;
//     		}
//     	}
//     }
    


//     REP(i,sz){
//     	VI co('z'-'a',0);
//     	FOR(j,i,sz,1){
//     		ll min = MOD;
//     		REP(z,26){
//     			ll te =  (z - (s[j] - 'a'))%26;
//     			if(te < 0){
//     				te +=26;
//     			}
//     			co[z]+=te;
//     			if(min > co[z]){
//     				min = co[z];
//     			}
//     		}
//     		cost[i][j]=min;
//     	}
//     }
//     // REP(i,sz){
//     // 	REP(j,sz){
//     // 		cout<<cost[i][j]<<" ";
//     // 	}
//     // 	cout<<endl;
//     // }


//     cout<<dp(0,k)<<endl;



//     return 0;
// }




// // /*
// //  * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
// //  *       Example:-   $ g++ -std=c++11 c++Template.cpp
// //  *
// //  * Author : Denzil Bernard  
// //  * Handle: 1_mn_RMY
// //  *
// //  */
// // // #include <bits/stdc++.h>
// // // C
// // #ifndef _GLIBCXX_NO_ASSERT
// // #include <cassert>
// // #endif
// // #include <cctype>
// // #include <cerrno>
// // #include <cfloat>
// // #include <ciso646>
// // #include <climits>
// // #include <clocale>
// // #include <cmath>
// // #include <csetjmp>
// // #include <csignal>
// // #include <cstdarg>
// // #include <cstddef>
// // #include <cstdio>
// // #include <cstdlib>
// // #include <cstring>
// // #include <ctime>

// // #if __cplusplus >= 201103L
// // #include <ccomplex>
// // #include <cfenv>
// // #include <cinttypes>
// // //#include <cstdalign>
// // #include <cstdbool>
// // #include <cstdint>
// // #include <ctgmath>
// // #include <cwchar>
// // #include <cwctype>
// // #endif

// // // C++
// // #include <algorithm>
// // #include <bitset>
// // #include <complex>
// // #include <deque>
// // #include <exception>
// // #include <fstream>
// // #include <functional>
// // #include <iomanip>
// // #include <ios>
// // #include <iosfwd>
// // #include <iostream>
// // #include <istream>
// // #include <iterator>
// // #include <limits>
// // #include <list>
// // #include <locale>
// // #include <map>
// // #include <memory>
// // #include <new>
// // #include <numeric>
// // #include <ostream>
// // #include <queue>
// // #include <set>
// // #include <sstream>
// // #include <stack>
// // #include <stdexcept>
// // #include <streambuf>
// // #include <string>
// // #include <typeinfo>
// // #include <utility>
// // #include <valarray>
// // #include <vector>

// // #if __cplusplus >= 201103L
// // #include <array>
// // #include <atomic>
// // #include <chrono>
// // #include <condition_variable>
// // #include <forward_list>
// // #include <future>
// // #include <initializer_list>
// // #include <mutex>
// // #include <random>
// // #include <ratio>
// // #include <regex>
// // #include <scoped_allocator>
// // #include <system_error>
// // #include <thread>
// // #include <tuple>
// // #include <typeindex>
// // #include <type_traits>
// // #include <unordered_map>
// // #include <unordered_set>
// // #endif

// // using namespace std;

// // /*******  All Required define Pre-Processors and typedef Constants *******/
// // #define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
// // #define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
// // #define REP(i, j) FOR(i, 0, j, 1)
// // #define RREP(i, j) RFOR(i, j, 0, 1)
// // #define all(cont) cont.begin(), cont.end()
// // #define rall(cont) cont.end(), cont.begin()
// // #define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
// // #define IN(A, B, C) assert( B <= A && A <= C)
// // #define MP make_pair
// // #define PB push_back
// // #define MOD 1000000007
// // #define read(type) readInt<type>()
// // #define ll long long
// // typedef pair< ll, ll> PII;
// // typedef vector<ll> VI;
// // typedef vector<PII> VII;
// // typedef vector<VI> VVI;
// // typedef map<ll,ll> MPII;
// // typedef set<ll> SETI;
// // typedef multiset<ll> MSETI;

// // ll SI(){
// //     ll x;
// //     cin>>x;
// //     return x;
// // }

// // int cost[2048+1][2048+1];
// // int DP[2048+1][32+1];
// // ll sz;

// // ll dp(ll idx, ll k){
// // 	// ll num_left = sz - idx;
// // 	// cout<<"calling dp of "<<idx<<" "<<k<<endl;

// // 	if(DP[idx][k]!=-1){
// // 		// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<DP[idx][k]<<endl;
// // 		return DP[idx][k];
// // 	}
// // 	else{
// // 		if(k==0){
// // 			DP[idx][k] = cost[idx][sz-1];
// // 			// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<DP[idx][k]<<endl;
// // 			return DP[idx][k];
// // 		}
// // 		else{
// // 			ll min = MOD;
// // 			FOR(i, idx+ 1, sz, 1){
// // 				ll te = dp(i,k-1) + cost[idx][i-1];
// // 				if(te < min){
// // 					min = te;
// // 				} 
// // 			}
// // 			DP[idx][k] = min;
// // 			// cout<<"\n DP OF "<<idx<<" "<<k<<" is "<<min<<endl;
// // 			return DP[idx][k];
// // 		}
// // 	}
// // }



// // /********** Main()  function **********/
// // int main()
// // {
    
    
// //     string s;
// //     cin>>s;
// //     sz = s.size();
// //     ll k = SI();
// //     REP(i,2048+1){
// //     	REP(j,2048+1){
// //     		cost[i][j]=-1;
// //     	}
// //     	REP(j,32+10){
// //     		DP[i][j]=-1;
// //     		if(i==sz-1){
// //     			DP[i][j]=0;
// //     		}
// //     	}
// //     }
    
// //     REP(i,sz){
// //     	VI co('z'-'a',0);
// //     	FOR(j,i,sz,1){
// //     		ll min = MOD;
// //     		REP(z,26){
// //     			ll te =  (z - (s[j] - 'a'))%26;
// //     			if(te < 0){
// //     				te +=26;
// //     			}
// //     			co[z]+=te;
// //     			if(min > co[z]){
// //     				min = co[z];
// //     			}
// //     		}
// //     		cost[i][j]=min;
// //     	}
// //     }
// //     REP(i,sz){
// //     	REP(j,sz){
// //     		cout<<cost[i][j]<<" ";
// //     	}
// //     	cout<<endl;
// //     }


// //     cout<<dp(0,k)<<endl;



// //     return 0;
// // }



