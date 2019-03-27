#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include <fstream>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
using namespace std;
int sI(){
    int c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    int n = 0;
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

int main(){
    string ip_filename = string("in25.txt");
    ifstream fil1;
    fil1.open(ip_filename.c_str());
    
    int n, m;
    fil1>>n;
    fil1>>m;
    
//    cout<<n<<" is "<<m<<"\n";
    int DP_prev[m];
    int DP_curr[m];
    REP(i,m){
        DP_prev[i]=1;
    }
//    char s[m];
    REP(i,n){
        string s;
        fil1>>s;
//        cout<<s<<"\n";
        //update the bottome
        REP(i,m){
            if(DP_prev[i]==1 && s[i]=='O'){
                DP_curr[i] = 1;
            }
            else{
                DP_curr[i] = 0;
            }
        }
        //sweep right
        int prev = 0;
        REP(i,m){
            if(prev==1 && s[i]=='O'){
                DP_curr[i] = 1;
            }
            prev = DP_curr[i];
        }
        //sweep left
        prev = 0;
        REP(i,m){
            if(prev==1 && s[m-1-i]=='O') {
                DP_curr[m-1-i] = 1;
            }
            prev = DP_curr[m-1-i];
        }
        REP(i,m){
            DP_prev[i] = DP_curr[i];
        }
//        getchar();
    }
    bool gai = true;
    REP(i,m){
        if(DP_curr[i]==1){
            cout<<1<<"\n";
            gai = false;
            break;
        }
    }
    if(gai){
        cout<<0<<"\n";
    }
}
