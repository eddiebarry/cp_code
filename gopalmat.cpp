#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<climits>
#define ll long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
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
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
    
    return gcd;
}


ll modInverse(long long a, long long m)
{
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return 1;
    else
    {
        // m is added to handle negative x
        long long res = (x%m + m) % m;
//        cout << "Modular multiplicative inverse is " << res;
        return res;
    }
}


ll nck(vector<ll>&fact, ll n, ll k){
    ll ans = 1;
    ans*= fact[n];
    cout<<ans<<" is temp ";
    ans*= modInverse(fact[k],MOD);
    ans%=MOD;
    ans*= modInverse(fact[n-k],MOD);
    cout<<ans<<" is temp " ;
    ans%=MOD;
    cout<<ans<<" is temp " ;
    return ans;
}



int main(){
    int t = sI();
    
    vector<ll> fact(100001);
    REP(i,100001){
        if(i==0){
            fact[i]=1;
        }
        else{
            fact[i]=fact[i-1]*i;
            fact[i]%=MOD;
        }
    }
    REP(i,t){
        ll n = sI(), k = sI();
        k--;
        n--;
        
        ll ans = nck(fact,k,n);
        ans*=ans;
        ans%=MOD;
        ans -= k;
        ans%=MOD;
        cout<<ans<<"\n";
    }
    
    
    

}
