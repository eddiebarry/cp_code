#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<climits>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
using namespace std;
int sI(){
    int x;
    cin>>x;
    return x;
}

long long sLL(){
    long long x;
    cin>>x;
    return x;
}

long long power(long long x,long long y, long long p)
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

long long mod(long long a){return a<0? -a:a;}

long long gcd(long long a, long long b)
{
    if (!a)
        return b;
    return gcd(b%a,a);
}

int main(){
    int t = sI();
    REP(i,t){
        long long a = sLL(), b = sLL(), n = sLL();
//        cout<<a<<" "<<b<<" "<<n<<"\n";
        long long temp1 = mod(a-b);
        if(temp1==0){
            a = power(a,n,MOD);
            b = power(b,n,MOD);
            long long temp  = (a+b)%MOD;
            cout<<temp%MOD<<"\n";
        }
        else{
            a = power(a,n,temp1);
            b = power(b,n,temp1);
            long long temp  = (a+b)%temp1;
            
            
            //        cout<<temp1<<" "<<temp<<"\n";
            long long ans = gcd(temp,temp1);

            cout<<ans%MOD<<"\n";
        }
//
//
//        cout<<0%0<<" is the frewakk\n";
    }
    
}
