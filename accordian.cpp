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
#include <iostream>

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
    string s;
    cin>>s;
    int n = s.size();

    bool start_bracket = false, start_colon = false, end_bracket = false, end_colon = false;

    ll start_idx = -1, end_idx = -1;
    REP(i,n){
        if(s[i]=='['){
            start_bracket = true;
        }
        if(start_bracket){
            if(s[i]==':'){
                start_colon = true;
                start_idx = i;
                break;
            }
        }
    }
    REP(i,n){
        // cout<<s[n-1-i]<<" ";
        if(s[n-1-i]==']'){
            end_bracket = true;
        }
        if(end_bracket){
            if(s[n-1-i]==':'){
                end_colon = true;
                end_idx = n - 1 -i;
                break;
            }
        }
    }
    // cout<<end_idx<<" "<<start_idx<<"\n";
    if((start_idx < end_idx) && start_bracket && start_colon && end_bracket && end_colon){
        ll ans = 0;
        FOR(i,start_idx,end_idx,1){
            if(s[i]==124){
                ans++;
            }
        }
        cout<<ans+4<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }





    return 0;
}



