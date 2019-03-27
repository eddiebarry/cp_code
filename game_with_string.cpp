// C++ program of above approach 
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
#define ll long long
using namespace std; 
  
// A utility function to get max of two integers 
int max (int x, int y) { return (x > y)? x : y; } 
  
// Returns the length of the longest palindromic subsequence in seq 

bool marked[10000000];

int lps(string &seq, int i, int j) 
{ 
// Base Case 1: If there is only 1 character 
if(marked[i]||marked[j]){
	return 0;
}
if (i == j) 
    return 0; 
  
// Base Case 2: If there are only 2  
// characters and both are same 
if (seq[i] == seq[j] && i + 1 == j){
	marked[i]=true;
	marked[j]=true;
	return 1;	
} 
    
  
// If the first and last characters match 
if (seq[i] == seq[j]){
	ll x = lps (seq, i+1, j-1);
    if(x > 0){
    	marked[i]=true;
    	marked[j]=true;
    	return x+1;
    }
    else{
    	return 0;
    }
}

// If the first and last characters do not match 
return ( lps(seq, i, j-1) + lps(seq, i+1, j) ) ; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    // char seq[] = "GEEKSFORGEEKS"; 
    string s;
    cin>>s;
    std::list<int> mylist;
    for(auto x : s){
    	mylist.push_back(x);
    }
    ll n = 0;
    auto it1 = mylist.begin();
    auto it2 = mylist.begin();
    ++it2;
    while(mylist.size() > 0){
    	if(*it2 == *it1){
    		n++;
    		if(it1==mylist.begin()){
	    		auto l =it1;
	    		auto r =it2;

	    		++it1;
	    		++it1;
	    		++it2;
	    		++it2;
	    		mylist.erase(l);
	    		mylist.erase(r);
	    	}
	    	else{
	    		auto l =it1;
	    		auto r =it2;
	    		
	    		--it1;
	    		++it2;
	    		// cout<<*it2<<" "<<*it1<<"\n";
	    		mylist.erase(l);
	    		mylist.erase(r);
	    	}
    	}
    	else{
    		++it2;
    		++it1;
    		if(it2==mylist.end()){
    			break;
    		}
    	}
    }


  	// cout<<n<<"\n";
  	if(n%2==0){
  		cout<<"No\n";
  	}
  	else{
  		cout<<"Yes\n";
  	}

    return 0; 
} 