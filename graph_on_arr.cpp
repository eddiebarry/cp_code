/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Edgar Monis
 * Handle: the_kng_in_the_!~th
 *
 */

/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define ll long long
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define SI Scan<int>()
#define SLL Scan<long long>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef unordered_map<int,int> MPII;
typedef unordered_map<long long,long long> MPLL;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';
    
    do
    {
        buf[--i] = x % 10 + '0';
        x/= 10;
    }while(x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T> inline T Scan()
{
    T n=0,s=1;
    char p=getchar();
    if(p=='-')
        s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-')
        p=getchar();
    if(p=='-')
        s=-1,p=getchar();
    while(p>='0'&&p<='9') {
        n = (n<< 3) + (n<< 1) + (p - '0');
        p=getchar();
    }
    
    return n*s;
}


ll DFS(vector<VI> &edges,int n){
    std::vector<bool> visited(n,false);
    stack<ll> stk;
    stk.push(0);
    while(!stk.empty()){
        //checkk 
        int x = stk.top();
        stk.pop();
        if(!visited[x]){
            for(auto y : edges[x]){
                if(!visited[y]){
                    stk.push(y);
                }
            }
        }
        visited[x]=true;

    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if(visited[i]){
            ans++;
        }
    }
    return ans;
}


ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

/********** Main()  function **********/
int main()
{
    
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt","r",stdin);
    //    //freopen("output.txt","w",stdout);
    //#endif
    ll t = SLL;
    while(t--){
        ll n = SLL;
        VLL v(n);
        MPLL freq;
        REP(i,n){
            v[i]=SLL;
            freq[v[i]]++;
        }
        vector<VI> edges(n);
        REP(i,n){
            FOR(j,i+1,n,1){
                if(gcd(v[i],v[j])==1){
                    // cout<<"adding edge between i anad j "<<i<<" "<<j<<"\n";
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        int x = DFS(edges,n);
        // cout<<x<<"\n";
        if(x!=n){
            cout<<1<<"\n";
            //put one prime from upper range
        //if theres atleast one number that is not equal to the prime, ans is valid
            if(freq[31]==n){
                v[0]=47;
            }
            else if(freq[37]==n){
                v[0]=47;
            }
            else if(freq[41]==n){
                v[0]=47;
            }
            else if(freq[43]==n){
                v[0]=47;
            }
            else if(freq[47]==n){
                v[0]=31;
            }
            else{
                freq[v[0]]--;
                v[0]=47;
                freq[47]++;
                if(freq[47]==n){
                    v[0]=31;
                }

            }

            REP(i,n){
                cout<<v[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<0<<"\n";
            REP(i,n){
                cout<<v[i]<<" ";
            }
            cout<<"\n";
        }


    }
    
    
    
    
    return 0;
}
