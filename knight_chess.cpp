/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Edgar Monis
 * Handle: the_kng_in_the_!~th
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

ll mod(ll a){
    return a< 0? -a:a;
}



/********** Main()  function **********/
int main()
{
    
    
    ll t = SI();
    while(t--){
        ll n = SI();
        VII v;
        set<PII> s;
        REP(i,n){
            ll x = SI(), y = SI();
            s.insert(MP(x+1, y+ 2));
            s.insert(MP(x-1, y+ 2));
            s.insert(MP(x+2, y+ 1));
            s.insert(MP(x-2, y+ 1));
            s.insert(MP(x+1, y- 2));
            s.insert(MP(x-1, y- 2));
            s.insert(MP(x+2, y- 1));
            s.insert(MP(x-2, y- 1));
        }
        ll k_x = SI(), k_y = SI();
        bool check = (s.find(MP(k_x+1,k_y+1))!= s.end() && s.find(MP(k_x,k_y+1))!= s.end() && s.find(MP(k_x-1,k_y+1))!= s.end());
        bool bot_chek = (s.find(MP(k_x,k_y))!= s.end() && s.find(MP(k_x-1,k_y))!= s.end() && s.find(MP(k_x+1,k_y))!= s.end() );
        bool top_chek = (s.find(MP(k_x,k_y-1))!= s.end() && s.find(MP(k_x-1,k_y-1))!= s.end() && s.find(MP(k_x+1,k_y-1))!= s.end() );
        
        if(check&& top_chek && bot_chek){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
        
    }
    return 0;
}

        // if(check){
        //     //up
        //     REP(i,n){
        //         v[i].second -= 1;
        //     }
        //     if(intersect(v)){
        //         //up right
        //         REP(i,n){
        //             v[i].first -= 1;
        //         }
        //         if (intersect(v)){
        //             //up left
        //             REP(i,n){
        //                 v[i].first -= -2;
        //             }
        //             if (intersect(v)){
        //                 //left
        //                 REP(i,n){
        //                     v[i].second += 1;
        //                 }
        //                 if (intersect(v)){
        //                 //right
        //                     REP(i,n){
        //                         v[i].first -= 2;
        //                     }
        //                     if (intersect(v)){
        //                     //bottom right
        //                         REP(i,n){
        //                             v[i].second += 1;
        //                         }
        //                         if (intersect(v)){
        //                         //bottom right
        //                             REP(i,n){
        //                                 v[i].second += 1;
        //                             }
                                         
        //                         }     
        //                     }
                                 
        //                 }

        //             }
        //         }
        //     }
        // }


