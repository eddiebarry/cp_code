#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< long long , pair< long long,long long > >
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

long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    
    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
    
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
    
    return gcd;
}

long long modInverse(long long a, long long m)
{
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return 1;
    else
    {
        // m is added to handle negative x
        long long res = (x%m + m) % m;
        return res;
    }
}

// C function for extended Euclidean Algorithm

long long fact[100001];
long long fact_inv[100001];
long long power_2_inv[100001];
long long DP[100001];

long long fn(long long x){
    long long temp = ( ( (fact[x]*power_2_inv[x/2]) %MOD) * fact_inv[x/2])%MOD;
    return temp;
}



int main(){
    
    fact[0]=1;
    fact_inv[0]=modInverse(fact[0],MOD);
    power_2_inv[0]=fact_inv[0];
    long long temp = 1;
    REP(i,100000){
        fact[i+1]=(fact[i]*(i+1))%MOD;
        fact_inv[i+1] = modInverse(fact[i+1],MOD);
        temp = (temp*2)%MOD;
        power_2_inv[i+1]= modInverse(temp,MOD);
    }
    long long n = sI();
    DP[0]=1;
    DP[1]=1;
    DP[2]=2;
    DP[3]=3;
    REP(i,n-3){
        int curr_sz = (i+4)*2;
        long long temp = 1;
        FOR(sz,2,curr_sz-1,2){
            cout<<sz<<"\n";
            FOR(st_idx,0,curr_sz-sz+1,2){
                long long end_idx = st_idx+sz-1;
                long long dif = DP[sz/2];
                            cout<<st_idx<<" "<<end_idx<<"\n";
                long long left = DP[st_idx/2];
                long long righ = DP[ (curr_sz - st_idx - sz)/2 ];
                cout<<(((((left*righ)%MOD)*dif)%MOD)*temp)%MOD<<"\n";
                DP[i+4]+= (((((left*righ)%MOD)*dif)%MOD)*temp)%MOD;
                DP[i+4]%=MOD;
            }
            cout<<"\n\n";
        }
    }
    REP(i,n){
        cout<<DP[i]<<" ";
    }
    
    
    n*=2;
    long long arr[n];
    REP(i,n){
        arr[i]=sI();
    }
    long long ans = 0;
    FOR(sz,2,n+1,2){
        
        long long temp = ((sz-3)*(sz-2))%MOD;
        temp*=power_2_inv[1];
        temp%=MOD;
        
        temp+=fn(sz-2);
        temp%=MOD;
        
        if(sz!=2){
            temp*=fn(sz-4);
            temp%=MOD;
        }
        //        cout<<"sz is "<<sz<<"temp is "<<temp<<"\n";
        FOR(st_idx,0,n,2){
            long long end_idx = st_idx+sz-1;
            long long dif = arr[end_idx]-arr[st_idx];
            //            cout<<st_idx<<" "<<end_idx<<"\n";
            long long left = fn(st_idx);
            long long righ = fn(n - st_idx - sz);
            
            ans+= (((((left*righ)%MOD)*dif)%MOD)*temp)%MOD;
        }
    }
    
    cout<<ans<<"\n";
}
