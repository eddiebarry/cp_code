
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
#define fenwick_tree_dt long long
const double pi=acos(-1.0);
typedef pair<ll, ll> PII;
typedef vector<ll> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef unordered_map<ll,ll> MPLL;
typedef unordered_map<long long,long long> MPLL;
typedef set<ll> SETLL;
typedef multiset<ll> MSETLL;

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

class BIT{
public:
    //initialise in O(n)
    BIT(vector<fenwick_tree_dt> arr){
        tree = vector<fenwick_tree_dt>(arr.size()+1,0);
        for(long long idx = 0; idx < arr.size(); idx++ ){
            tree[idx+1] = arr[idx];
        }
        for(long long idx = 1; idx < tree.size(); idx++ ){
            long long temp = (idx&-idx) + idx;
            if(temp < tree.size() ){
                tree[temp] +=tree[idx];
            }
        }
    }
    //only works for range sum with updates
    fenwick_tree_dt prefix_query(long long idx){
        fenwick_tree_dt result = 0;
        for(++idx; idx > 0; idx -= idx&-idx){
            result+=tree[idx];
        }
        return result;
    }
    //this operation will not give correct values for range updates
    fenwick_tree_dt range_query(long long from, long long to){
        return prefix_query(to) - prefix_query(from-1);
    }
    //gives correct for range updates
    fenwick_tree_dt point_query(long long idx){
        return prefix_query(idx) - prefix_query(idx-1);
    }
    //updates the value by add
    void update(long long idx , fenwick_tree_dt add){
        for(++idx; idx < tree.size(); idx+=idx & -idx){
            tree[idx] +=add;
        }
    }

    ll binary_search( ll k){
    ll start = 0, end = tree.size();
    ll mid;
    while(end-start!=1){
        mid = start + end;
        mid/=2;
        ll val = prefix_query(mid);
        if(val<k){
            start = mid;
        }
        else if(val>k){
            end = mid;
        }
        else{
            break;
        }
    }
    return mid;

}

private:
    vector<fenwick_tree_dt> tree;
};











/********** Main()  function **********/
int main()
{
    int t = SI;
    while(t--){
        int n = SI;
        VI v(n);
        ll max = -1;
        ll first = -1;
        REP(i,n){
            v[i]=SI;
            if(v[i]!=-1&&first==-1){
                first=i;
            }
            if(v[i]>max){
                max = v[i];
            }
        }
        //check if inf
        if(first==-1){
            cout<<"inf\n";
            goto label;
            // return 0;
        }
        else{
            int curr = v[first];
            bool flag = true;
            FOR(i,first,n,1){
                if(v[i]==curr||v[i]==-1){
                    curr++;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<"inf\n";
                goto label;
                // return 0;
            }

        }
        //
        RFOR(k, max+n+1,max, 1){
            //check if valid for k;
            ll curr = v[first];
            bool flag =  true;
            FOR(i,first,n,1){
                if(v[i]==curr||v[i]==-1){
                    curr++;
                }
                else{
                    flag = false;
                    break;
                }
                if(curr==k+1){
                    curr=1;
                }
            }
            if(flag){
                cout<<k<<"\n";
                goto label;
                // return 0;
            }
        }
        cout<<"impossible\n";
        goto label;
        // return 0;
        label:
        {
            
        }
    }
    
    
    
    return 0;
}
