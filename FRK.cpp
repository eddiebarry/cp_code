#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
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
    int n = sI();
    int ans = 0;
    REP(i,n){
        string s;
        cin>>s;
        REP(i,s.length()-1){
            if(s[i]=='c'&&s[i+1]=='h'){
                ans++;
                break;
            }
            if(s[i]=='h'&&s[i+1]=='e'){
                ans++;
                break;
            }
            if(s[i]=='e'&&s[i+1]=='f'){
                ans++;
                break;
            }
        }
    }
    cout<<ans;
}
