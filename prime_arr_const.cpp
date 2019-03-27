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
const long long MAX_SIZE = 10000001;
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
void manipulated_seive(int N)
{
    isprime[0] = isprime[1] = false ;
    for (long long int i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }        for (long long int j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}
int main()
{
    int N = 10000000 ; // Must be less than MAX_SIZE
    set<int> primes;
    manipulated_seive(N);
    for (int i=0; i<prime.size() && prime[i] <= N ; i++)
        primes.insert(prime[i]);
    
    int x;
    cin>>x;
    int arr[x];
    REP(i,x){
        cin>>arr[i];
    }
    int ans[x];
    
    REP(i,x){
        ans[i]=-1;
        if(primes.find(arr[i])!=primes.end()){
            ans[i]=arr[i];
            primes.erase(arr[i]);
        }
    }
    REP(i,x){
        if(ans[i]==-1){
            auto x = primes.lower_bound(arr[i]);
            ans[i]=*x;
            primes.erase(x);
        }
    }
    REP(i,x){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
