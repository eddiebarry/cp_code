
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#define FOR(i, j, k, in) for (long long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;

long long sI(){
    long long c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    long long n = 0;
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    if(flag){
        return n;
    }
    else{
        return n*-1;
    }
}


long long score(string &s, long long &a_cnt, long long &b_cnt){
    long long score = 0;
    REP(i,s.size()){
        if(s[i]=='a'){
            a_cnt++;
        }
        else{
            b_cnt++;
        }
        if(a_cnt>b_cnt){
            score++;
        }
    }
    return score;
}



int main(){
    long long t;
    cin>>t;
    REP(i,t){
        string temp;
        cin>>temp;
        long long n;
        cin>>n;
        long long x = 0, y = 0;
        long long scr = score(temp,x,y);
        if(x==y){
            cout<<scr*n<<"\n";
        }
        else if(x>y){
            string s="";
            int small = n < 1000 ? n : 1000;
            REP(i,small){
                s+=temp;
            }
            x = 0,y=0;
            scr = score(s,x,y);
            if(small==n){
                cout<<scr<<"\n";
            }
            else{
                cout<<scr + ( (n-1000) * temp.size() ) <<"\n";
            }
        }
        else{
            string s="";
            int small = n < 1000 ? n : 1000;
            REP(i,small){
                s+=temp;
            }
            x = 0,y=0;
            scr = score(s,x,y);
            if(small==n){
                cout<<scr<<"\n";
            }
            else{
                cout<<scr<<"\n";
            }
        }
    }
}
     
