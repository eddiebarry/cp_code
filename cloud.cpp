
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
    vector<long long> num_cores(1e6+10,0);
    BIT core(num_cores);
    vector<long long> cost_cores(1e6+10,0);
    BIT costs(cost_cores);
    // cout<<bit.prefix_query(7);
    
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt","r",stdin);
    //    //freopen("output.txt","w",stdout);
    //#endif

    ll n = SLL, k = SLL, m =SLL;
    VII start[n+1];
    VII end[n+1];
    VI price(m);
    VI cores(m);
    REP(i,m){
        ll s = SLL, e = SLL, c = SLL, p = SLL;
        start[s].PB(MP(c,i));
        end[e].PB(MP(c,i));
        price[i]=p;
        cores[i]=c;
    }

    ll ans = 0;
    multiset<ll> c;
    REP(i,n+1){
        // cout<<i<<" is the ith day\n";
        //add to trees
        for(auto x : start[i]){
            ll num_cores = x.first;
            ll id = x.second;
            // cout<<"id is added "<<id<<"\n";
            ll pr = price[id];
            core.update(pr,num_cores);
            costs.update(pr,num_cores*pr);
            c.insert(pr);
        }
        ll costs_ = 0;
        ll idx_to_sum_till = core.binary_search(k);

        // if(i==4){
        //     for(auto x:c){
        //         cout<<x<<" ";
        //     }
        //     cout<<"\n";
        // }

        ll temp_cores_to_be_added = core.prefix_query(idx_to_sum_till);
        // if(i==4){
        //         // cout<<temp_cores_to_be_added<<" is the temp cores to be added \n";
        // }
        if(temp_cores_to_be_added<k){
            // find next largest cost available and add that to cost as well

            auto it =  c.upper_bound(idx_to_sum_till);
            if(it!=c.end()){
                ll pr = *it;
                int present_in_next = core.point_query(pr);
                if(present_in_next < k - temp_cores_to_be_added){
                    costs_ += pr * present_in_next;
                }
                else{
                    costs_ += pr * (k - temp_cores_to_be_added);    
                }
                
            }
        }
        else if(temp_cores_to_be_added>k){
            costs_ -= idx_to_sum_till*(temp_cores_to_be_added-k);
        }


        // cout<<"idx_to_sum_till is "<<idx_to_sum_till<<"\n";
        costs_ += costs.prefix_query(idx_to_sum_till);
        ans+= costs_;
        // cout<<"price of the day is "<<costs_<<"\n";
        // cout<<ans<<" is ans\n";






        //remove trees;
        for(auto x : end[i]){

            ll num_cores = x.first;
            ll id = x.second;
            // cout<<"id is removed "<<id<<"\n";
            ll pr = price[id];
            core.update(pr,-num_cores);
            costs.update(pr,-num_cores*pr);
            c.erase(c.find(pr));
        }
        // cout<<i<<" is the end of ith day\n\n\n\n\n\n";
    }

    cout<<ans;
    
    
    
    return 0;
}
