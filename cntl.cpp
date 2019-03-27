
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

long long arr[100000];
long long fact[100001];

int main(){
    int t = sI();
    long temp = 1;
    arr[0]=1;
    fact[0]=1;
    REP(i,100000 - 1){
        arr[i+1]=arr[i];
        temp*=2;
        temp%=MOD;
        arr[i+1]+=temp;
        arr[i+1]%=MOD;
        
    }
    REP(i,100001){
        fact[i+1] *= fact[i]*(i+1);
        fact[i+1] %=MOD;
    }
    REP(i,t){
        int n = sI();
        int k = sI();
        int num_non_zero, num_zero;
        long ans;
        num_non_zero = k;
        num_zero = n-k;
        if(num_zero%2!=0){
            //is odd
            //we want number of ways to get 1
            num_non_zero--;
            num_zero++;
            //answer will be 11111...1110
            ans = arr[k-1]-1;
            ans+=MOD;
            ans%=MOD;
            //ways to fill in will be nCk/2! +
        }
        else{
            //is even
            //number o ways to get 0
            ans = arr[k-1];
            //answer wil be 111111...1111
        }
        //ways to fill in will be nCnum_non_zero * num_non_zer! + (n-num_non_zero)C2*k
        
        
        long long ways = 1;
        REP(i,num_non_zero){
            ways *= (n-i);
            ways %= MOD;
        }
        
        long long temp = num_zero;
        REP(i,2){
            temp *= (n-i);
            temp %= MOD;
        }
        temp*=500000004;
        temp%=MOD;
        temp*=k;
        temp%=MOD;
        
        
        ways+=temp;
        ways%=MOD;
        cout<<ans<<" "<<ways<<"\n";
        
        
        
    }
    return 0;
}
