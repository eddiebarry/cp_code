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
#define MOD 1050000007
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

// std::vector<VI> paths_a;
// std::vector<VI> paths_b;
int label_path_a[105+1][105+1];
int label_path_b[105+1][105+1];
int label_node_a[105+1][105+1];
int label_node_b[105+1][105+1];
bool a_reach[105+1];
bool b_reach[105+1];
multimap<ll,ll> labs_a;
multimap<ll,ll> labs_b;
ll h, h_1;
ll m;
ll t;


int check(ll curr, ll curr_b,ll dest_1,ll dest_2,map<string,ll> &visited_a, multimap<ll,ll> &cycle,ll prev){
    // visited_a[curr]++;
    string key = to_string(prev);
    key+="*";
    key+=to_string(curr);
    // cout<<"\n key is "<<key<<" \n";
    visited_a[key]++;
    if(visited_a[key]>1){
        //search if curr_b_is present
        bool boo = false;
        auto it = cycle.equal_range(curr);
        for(auto itr = it.first ; itr != it.second; ++itr){
            ll temp = itr->second;
            if(temp==curr_b){
                boo = true;
            }
        }
        if(!boo){
            return 1;
        }
        //else exit
    }
    cycle.insert(make_pair(curr,curr_b) );
    // if(true){
    //     if(visited_a[curr]>1){
    //         if(cycle.find(curr)!=cycle.end()){
    //             // return 0;
    //         }
    //         else{
    //             return 1;
    //         }
    //     }
    //     cycle.insert(make_pair(curr,curr_b));
    //     // cycle[curr]=curr_b;
    // }

    // if(curr==dest_1 && curr_b==dest_2){
    //     return 0;
    // }
    if(visited_a[key]>m){
        return 0 ;
    }

    if(true){
        ll ans = 0;
        //check every posssible node you can visit from curr_pos
        REP(z,105){
            ll label = label_path_a[curr][1+z];
            if(label==0){
                continue;
            }
            ll node_id = 1+z;
            if(true){
                //find equivalent and call again
                ll nd_labl_pnt = label_node_b[curr_b][label];
                if(nd_labl_pnt==-1){
                    ans+=1;
                    // cout<<curr<<" "<<curr_b<<" "<<dest_1<<" "<<dest_2<<"\n"<<node_id<<" "<<label<<"\n";
                    // for (int i = 0; i < 10; ++i)
                    // {
                    //     /* code */
                    //     cout<< visited_a[i]<<" ";
                    // }
                    // cout<<"\n";
                    return ans;
                }
                else{
                    ans+=check(node_id,nd_labl_pnt,dest_1,dest_2,visited_a,cycle,curr);
                    if(ans>0){
                        return ans;
                    }
                }
                // ans += check(node_that_label_points_to)
            }

        }
        /**
        //if there is an equivalent edge in the other graph, call the function
        //if there isnt, check if it is possible to win from that node in current graph
        //return 1
        //else return 0
        **/
        REP(z,105){
            ll label = label_path_b[curr_b][1+z];
            if(label==0){
                continue;
            }
            ll node_id = 1+z;
            if(b_reach[node_id]||true){
                //find equivalent and call again
                ll nd_labl_pnt = label_node_a[curr][label];
                if(nd_labl_pnt==-1){
                    ans+=1;
                    return ans;
                }
                else{
                    // ans+=check(nd_labl_pnt,node_id,dest_1,dest_2,visited_a,cycle,curr);
                    if(ans>0){
                        return ans;
                    }
                }
                // ans += check(node_that_label_points_to)
            }
        }
        return ans;
    }

}
  
// Driver program 
int main() 
{ 
    // Create a graph given in the above diagram
    t = SI();
    REP(i,t){
        m = SI();
        ll n = SI(), n_ed = SI(), dest = SI();
        VI children_n[n+1];
        REP(i,105+1){
            REP(j,105+1){
                label_path_a[i][j]=0;
                label_path_b[i][j]=0;
                label_node_a[i][j]=-1;
                label_node_b[i][j]=-1;
            }
        }
        REP(i,n_ed){
            ll x = SI(), y = SI(), col = SI();
            // x--;
            // y--;
            label_path_a[x][0]++;
            label_path_a[x][y]=col;
            label_node_a[x][col]=y;
            children_n[y].push_back(x);
        }
        
        ll k = SI(), m_ed = SI(), dest_2 = SI();
        VI children_m[k+1];
        REP(i,m_ed){
            ll x = SI(), y = SI(), col = SI();
            // x--;
            // y--;
            label_path_b[x][0]++;
            label_path_b[x][y]=col;
            label_node_b[x][col]=y;
            children_m[y].push_back(x);
        }
        //dfs
        REP(i,105+1){
            a_reach[i]=false;
            b_reach[i]=false;
        }
        stack<ll>to_visit;
        to_visit.push(dest);
        while(!to_visit.empty()){
            ll curr = to_visit.top();
            to_visit.pop();
            if(!a_reach[curr]){
                a_reach[curr]=true;
                for(auto x : children_n[curr]){
                    to_visit.push(x);
                }
            }
        }
        to_visit.push(dest_2);
        while(!to_visit.empty()){
            ll curr = to_visit.top();
            to_visit.pop();
            if(!b_reach[curr]){
                b_reach[curr]=true;
                for(auto x : children_m[curr]){
                    to_visit.push(x);
                }
            }
        }
        // for(auto x : a_reach){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        // for(auto x : b_reach){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        map<string,ll> visited_a;
        multimap<ll,ll> cycle;
        // VI visited_b(105+1,false);;
        ll ans = check(1,1,dest,dest_2,visited_a,cycle,-1);

        if(ans==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

  
    return 0; 
} 


// 4
// 2
// 3 3 3
// 1 2 1
// 1 3 2
// 2 3 1
// 3 2 3
// 1 3 1
// 1 2 2
// 3
// 9 12 9
// 1 2 1
// 2 3 2
// 3 4 1
// 4 5 2
// 5 6 1
// 6 7 2
// 7 8 1
// 8 1 2
// 1 9 3
// 3 9 3
// 5 9 3
// 7 9 3
// 3 3 3
// 1 2 1
// 2 1 2
// 1 3 3
// 10
// 4 4 3
// 1 2 1
// 1 4 2
// 2 3 3 
// 4 3 4
// 7 5 7
// 1 4 1
// 6 7 4
// 4 7 3
// 1 6 2
// 4 5 6
// 3
// 4 3 3
// 1 2 1
// 2 3 2
// 2 4 3
// 3 2 3
// 1 2 1
// 2 3 2


    // if(true){
    //     if(visited_a[curr]>1){
    //         if(cycle.find(curr)!=cycle.end()){
    //             // return 0;
    //         }
    //         else{
    //             return 1;
    //         }
    //     }
    //     cycle.insert(make_pair(curr,curr_b));
    //     // cycle[curr]=curr_b;
    // }

    // if(curr==dest_1 && curr_b==dest_2){
    //     return 0;
    // }
    // if(visited_a[curr]>m){
    //     return 0 ;
    // }
/**
        ll m = SI();
        ll n = SI(), e = SI();
        h = SI();
        
        Graph a(n);

        labs_a.clear();
        labs_b.clear();

        REP(i,105+1){
            REP(j,105+1){
                label_path_a[i][j]=-1;
                label_path_b[i][j]=-1;
            }
        }

        REP(i,e){
            ll x = SI(), y = SI(), lab = SI();
            a.addEdge(x-1,y-1);
            // labs_a[((x-1)*1050 + (y-1))] = lab-1;
            labs_a.insert( MP ((x-1)*1050 + (y-1) ,  lab-1)) ;
            label_path_a[x-1][lab-1]=y-1;
        }
        
        ll k = SI(), edge = SI();
        h_1 = SI();


        Graph b(k);
        REP(i,edge){
            ll x = SI(), y = SI(), lab = SI();
            b.addEdge(x-1,y-1);
            labs_b.insert( MP ((x-1)*1050 + (y-1) ,  lab-1)) ;
            label_path_b[x-1][lab-1]=y-1;
        }
        bool no_mirror = a.printAllPaths(0,h-1,true);
        no_mirror = (no_mirror && b.printAllPaths(0,h_1-1, false));

        unordered_set<string>pa;
        


        if(no_mirror){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

        **/
// 1
// 2
// 3 3 3
// 1 2 1
// 1 3 2
// 2 3 1
// 3 3 3
// 1 2 1
// 1 3 2
// 2 3 1


        // for(auto x : paths){
        //     string temp = "";
        //     // cout<<"\ntemp being inserted "<<temp<<endl;
        //     REP(i,x.size()-1){
        //         temp+= to_string(labs_a[  x[i]*1050 + x[i+1]    ] );
        //         temp+="*";
        //     }
        //     // cout<<"\ntemp being inserted "<<temp<<endl;
        //     pa.insert(temp);
        //     // cout<<"\n";
        // }
        // // cout<<"\**************************\n";
        // for(auto x : paths_a){
        //     string temp = "";
        //     REP(i,x.size()-1){
        //         temp+= to_string(labs_b[  x[i]*1050 + x[i+1]    ] );
        //         temp+="*";
        //     }
        //     // cout<<"\ntemp being erased "<<temp<<"\n";
        //     if(pa.find(temp)==pa.end()){
        //         no_mirror = true;
        //         break;
        //     }
        //     // cout<<"\ntemp being erased "<<temp<<"\n";
        //     pa.erase(pa.find(temp));
        //     // cout<<"\n";
        // }
        // if(pa.size()>0){
        //     no_mirror = true;
        // }