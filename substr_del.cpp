/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Denzil Bernard  
 * Handle: 1_mn_RMY
 *
 */
#include<bits/stdc++.h>

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
    string s;
    while(cin>>s){
        
        // cout<<s
        int last['z'-'a'];
        int added['z'-'a'];
        REP(i, 'z' - 'a'){
            last[i] = 0;
            added[i] = 0;
        }
        
        int idx = 0;
        for(auto x : s){
            last[x-'a']=idx++;
        }
        idx = 0;
        set < pair<char, int> > min_heap;
        string ans="";
        for(auto x : s){
            //if idx is last current, empty heap
            if(added[x-'a']==0){
                min_heap.insert(MP(x,idx));
                if(idx == last[x-'a']){
                    set<char>to_erase;
                    for(auto y : min_heap){
                        ans += y;
                        added[y-'a']=1;
                        to_erase.insert(y);
                        if(y==x){
                            break;
                        }
                    }
                    for(auto y : to_erase){
                        min_heap.erase(y);
                    }
                }
            }
            idx++;
        }
        cout<<ans<<endl;
    }
    return 0;
}



