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

long long power(long long x, long long y, long long p)
{
    long long res = 1;      // Initialize result
    
    x = x % p;  // Update x if it is more than or
    // equal to p
    
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
        
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main(){
    int t = sI();
    REP(i,t){
        long long n;
        cin>>n;
        int w;
        cin>>w;
        //cout<<"w is "<<w<<"\n";
        if(w>8 || w < -9){
            cout<<0<<"\n";
            continue;
        }
        else{
            long long ans;
            if(w>=0){
                int num = 9 - w;
                n-=2;
                ans = power(10,n,MOD);
                ans *= num;
                ans%=MOD;
            }
            else{
                int num = 10 + w;
                //cout<<"num is "<<num<<"\n";
                n-=2;
                ans = power(10,n,MOD);
                ans *= num;
                ans%=MOD;
            }
            cout<<ans<<"\n";
        }
    }
}
