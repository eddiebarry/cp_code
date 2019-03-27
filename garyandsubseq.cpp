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


bool check_if(int x, int y, vector<string> &v){
    string a = v[x];
    string b = v[y];
    if(a.size()==b.size()){
        int idx = 0;
        for(auto x : b){
            if(x==a[idx]){
                idx++;
                if(idx==a.size()){
                    return true;
                }
            }
        }
        idx = 0;
        for(auto x : a){
            if(x==b[idx]){
                idx++;
                if(idx==b.size()){
                    return true;
                }
            }
        }
    }
    else{
        //check smaller
        if(a.size() < b.size()){
            int idx = 0;
            for(auto x : b){
                if(x==a[idx]){
                    idx++;
                    if(idx==a.size()){
                        return true;
                    }
                }
            }
        }
        else{
            int idx = 0;
            for(auto x : a){
                if(x==b[idx]){
                    idx++;
                    if(idx==b.size()){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/********** Main()  function **********/
int main()
{
    
    
    ll n = SI(), q = SI();
    std::vector<string> v;
    REP(i,n){
        string s;
        cin>>s;
        v.PB(s);
    }
    REP(i,q){
        int x = SI(),y = SI();
        x--;
        y--;
        if(check_if(x,y,v)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}



