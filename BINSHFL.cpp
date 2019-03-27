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
#define MOD 1000000007
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


long long sLL(){
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

int setBIT(long long a){
    int cnt = 0;
    while(a>0){
        if(a%2==1){
            cnt++;
        }
        a/=2;
    }
    return cnt;
}


int main(){
    int t = sI();
    while(t--){
        long long a = sLL(), b = sLL();
        int set_a;
        int set_b;
        int ans = 0;
    label:
        set_a = setBIT(a);
        set_b = setBIT(b);
        if(b%2==1 && set_b>set_a){
            cout<<set_b-set_a+ans<<"\n";
        }
        else if(b%2==1){
            if(a==b){
                cout<<0+ans<<"\n";
            }
            else{
                cout<<2+ans<<"\n";
            }
        }
        else{
            b--;
            ans++;
            goto label;
        }
        
        
    }
}
