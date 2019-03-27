/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Denzil Bernard  
 * Handle: 1_mn_RMY
 *
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

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


ll SI(){
    ll x;
    cin>>x;
    return x;
}


/********** Main()  function **********/
int main()
{
    
    
    ll q = SI();
    REP(i,q){
        ll n = SI();
        std::vector<pair<pair <int,int>, int > > v;
        REP(i,n){
            v.push_back(MP(MP(SI(),SI()),i));
        }
        ll max_end = -1;
        sort(v.begin(),v.end());
        
        ll curr = 1;
        std::vector<int> ans(n,0);
        bool an = true;

        multiset<ll>stk;

        REP(i,n){


            ll end = v[i].first.second;
            ll start = v[i].first.first;
            ll idx = v[i].second;
            // stk.insert(end);
            stk.insert(start);
            while(*(stk.begin()) < start){
                stk.erase(stk.begin());
            }
            stk.erase(stk.begin());
            ans[idx] = i % 2 + 1;
            stk.insert(end);
            if(stk.size() > 2){
                cout<<-1<<"\n";
                an = false;
                break;
            }

        }
        if(an){
            for(auto x : ans){
                cout<<x<<" ";
            }
            cout<<"\n";
        }



    }
    return 0;
}


            
            // curr == stk.size();
            // ll end = v[i].first.second;
            // ll start = v[i].first.first;
            // ll idx = v[i].second;

            // // cout<<start<<" "<<end<<" "<<idx<<"\n";
            // ans[idx] = i % 2 + 1;



            // if(max_end < start){
            //     curr--;
            // }
            // max_end = max(max_end,end);

            // if(curr>2){
            //     cout<<-1<<"\n";
            //     an = false;
            //     break;
            // }

