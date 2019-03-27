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

ll gcd(ll x, ll y){
    if(x==0){
        return y;
    }
    else{
        return(gcd(y%x,x));
    }
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
        VII v;
        VI fast;
        int first = -1;
        bool ans = false;
        REP(i,n){
            ll x = SLL;
            fast.PB(x);
            if(x==-1){
                continue;
            }
            else{
                v.PB(MP(x,i));
                if(first==-1){
                    first = i;
                }
            }
        }
        //check if inf
        if(v.size()==0){
            cout<<"inf\n";
            ans = true;
        }
        if(!ans){
            //find corresponding 1 positions
            set<ll>one_pos ;
            for(auto x: v){
                ll num = x.first;
                ll idx = x.second;

                ll corresponding_1_pos = idx - num + 1;
                one_pos.insert(corresponding_1_pos);
            }
            if(one_pos.size()==1){
                cout<<"inf\n";
                ans = true;
            }
            if(!ans){
                //find gcd;
                VI one_pos_idx;
                VI one_pos_dis;
                for(auto x: one_pos){
                    one_pos_idx.PB(x);
                }
                ll sz = one_pos_idx.size();
                REP(i,sz-1){
                    one_pos_dis.PB(one_pos_idx[i+1] - one_pos_idx[i]);
                }
                ll Gcd = one_pos_dis[0];
                REP(i,sz-1){
                    Gcd = gcd(one_pos_dis[i],Gcd);
                }
                // cout<<"gcd is "<<Gcd<<"\n";
                ll max_ans = -1;
                for(ll i = 1; i*i <= Gcd; i++){
                    if(Gcd%i==0){
                        //i is a factor;
                        bool is_ans = true;
                        ll exp = fast[first];
                        FOR(j,first,n,1){
                            // cout<<exp<<" "<<fast[j]<<" is exp \n";
                            // cout<<n<<" "<<j<<" first \n";
                            if(exp!=fast[j] && fast[j]!=-1){
                                is_ans = false;
                                break;
                            }
                            exp++;
                            if(exp==i+1){
                                exp = 1;
                            }
                        }
                        if(is_ans){
                            if(i> max_ans){
                                max_ans = i;
                            }
                        }
                        is_ans = true;
                        //gcd/i is a factor
                        ll sec = Gcd /i;
                        exp = fast[first];
                        FOR(j,first,n,1){
                            // cout<<exp<<" "<<fast[j]<<" is exp \n";
                            if(exp!=fast[j] && fast[j]!=-1){
                                is_ans = false;
                                break;
                            }
                            exp++;
                            if(exp==sec+1){
                                exp = 1;
                            }
                        }
                        if(is_ans){
                            if(sec> max_ans){
                                max_ans = sec;
                            }
                        }

                    }

                }
                if(max_ans==-1){
                    cout<<"impossible\n";
                }
                else{
                    cout<<max_ans<<"\n";
                }
            }

        }
        

    }
    
    
    
    
    return 0;
}
