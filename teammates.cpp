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
#include<unordered_map>
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
/************************************/


/******* Debugging Class Template *******/
//#define DEBUG
//
//#ifdef DEBUG
//
//#define debug(args...)     (Debugger()) , args
//
//class Debugger
//{
//public:
//    Debugger(const std::string& _separator = " - ") :
//    first(true), separator(_separator){}
//
//    template<typename ObjectType> Debugger& operator , (const ObjectType& v)
//    {
//        if(!first)
//            std:cerr << separator;
//        std::cerr << v;
//        first = false;
//        return *this;
//    }
//    ~Debugger() {  std:cerr << endl;}
//
//private:
//    bool first;
//    std::string separator;
//};
//
//#else
//#define debug(args...)                  // Just strip off all debug tokens
//#endif
const int globalsize = 1e5+10;
const ll M = 1e9+7;
ll precalfactorial[globalsize];
ll INVfactorial[globalsize];
ll precalpowers[globalsize];
ll INVpowers[globalsize];


ll inverseMod(ll a, ll m) {
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    
    return x;
}

void preCalc(){
    precalfactorial[0]=1;
    INVfactorial[0]=1;
    precalpowers[0]=1;
    INVpowers[0]=1;
    for(int i=1;i<globalsize;i++){
        precalfactorial[i] = (precalfactorial[i-1]*i)%M;
        INVfactorial[i] = inverseMod(precalfactorial[i],MOD);
        precalpowers[i] = (precalpowers[i-1]*2)%M;
        INVpowers[i] = inverseMod(precalpowers[i],MOD);
    }
}


ll NCR(ll n, ll r){
    ll ncr =  precalfactorial[n];
    ncr *= INVfactorial[r];
    ncr%=MOD;
    ncr *= INVfactorial[n-r];
    ncr%=MOD;
    
    return ncr;
}

ll totalWays(ll n){
    if(n<=0) return 1LL;
    ll k1 = precalfactorial[n];
    ll power_to_cal = n/2+1;
    ll power_cal = precalpowers[power_to_cal];
    ll ans = ((k1)*(inverseMod(power_cal,M)))%M;
    return ans;
}

ll FORM_PAIR(ll cnt, ll pair){
    ll temp = precalfactorial[cnt];
    temp *= INVfactorial[cnt - 2* pair];
    temp%= MOD;
    temp *= INVpowers[pair];
    temp%= MOD;
    temp *= INVfactorial[pair];
    temp%= MOD;
    
    return temp;
}


/**************************************/

ll DP(ll i, ll cnt, MPLL &DP_map, VII & v){
    //    i++;
    //    i--;
//        cout<<" calculating dp "<<i<<" "<<cnt<<" "<<endl;
    
    if(i<0){
        return 1;
    }
    if(cnt <= 0){
        return DP(i-1, v[i-1].second, DP_map,v);
    }
    
    if(DP_map.find(i*1e6+ cnt)!= DP_map.end()){
        return DP_map[i*1e6+ cnt];
    }
    else{
        
        ll temp = 1;
        ll temp_sub = 0;
        ll self_pair_num = 0;
        ll temp_cnt = cnt;
        
        
        while(cnt > v[i-1].second){
            cnt-=2;
            self_pair_num +=2;
        }
//        if(cnt%2==1){
//            temp*=cnt;
//            temp%=MOD;
//            temp*=v[i-1].second;
//            v[i-1].second--;
//            cnt--;
//        }
        FOR(X,0,cnt+1,2){
            ll cross_pairs = cnt - ( 2 * (X/2) );
            ll self_pair = X/2;
            
            
            
            ll temp = FORM_PAIR(cnt, self_pair);
            temp%= MOD;
            temp *= precalfactorial[cross_pairs];
            temp%= MOD;
            temp*=precalfactorial[v[i-1].second];
            temp%= MOD;
            temp*=INVfactorial[v[i-1].second-cross_pairs];
            temp%= MOD;
            temp*=INVfactorial[cross_pairs];
            temp%= MOD;
//                        cout<<"going to calculate dp \n";
//            cout<<i<<" "<<v[i-1].second<<" "<<cross_pairs<<"\n";
            temp *= DP(i-1, v[i-1].second - cross_pairs, DP_map, v);
            temp%= MOD;
            temp_sub += temp;
            temp_sub %= MOD;
            
        }
        //
//                cout<<temp<<"\n";
//        temp *= NCR(temp_cnt,self_pair_num);
//        temp %= MOD;
        
        temp *=  precalfactorial[temp_cnt];
        temp %= MOD;
        temp *=  precalfactorial[temp_cnt-self_pair_num];
        temp %= MOD;
        temp *= INVfactorial[self_pair_num/2];
        temp %= MOD;
        
//        temp *= FORM_PAIR(temp_cnt,self_pair_num/2);
//        temp %= MOD;
        temp *= temp_sub;
        temp %= MOD;
        
        DP_map[i*1e6+ temp_cnt] = temp;
        
        return DP_map[i*1e6+ temp_cnt];
    }
}






/******** User-defined Function *******/


/**************************************/


/********** Main()  function **********/
int main()
{
    
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt","r",stdin);
    //    //freopen("output.txt","w",stdout);
    //#endif
    
    preCalc();
    int tc;
    tc = SI;
    
    while(tc--){
        int n = SI;
        VI v;
        SETI s;
        REP(i,n){
            int x = SI;
            v.PB(x);
            s.insert(x);
        }
        MPII first_app;
        sort(all(v));
        REP(i,n){
            if(first_app.find(v[i])==first_app.end()){
                first_app[v[i]]=i;
            }
        }
        ll ans = 1;
        REP(i,n){
            //find first appearence of predecessor and
            ll temp = 1;
            
            if(v[i]==*s.begin() ){
                temp = i + 1;;
            }
            else{
                auto it = s.lower_bound(v[i]);
                it--;
                int prev = *it;
                temp += i - first_app[prev];
            }
            ans*= temp;
            ans %= MOD;
            
            
            i++;
        }
        cout<<ans<<"\n";
        
    }
    return 0;
}
