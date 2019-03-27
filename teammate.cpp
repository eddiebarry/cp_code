#include <bits/stdc++.h>
//#include <bits/
#define mp(a,b)   make_pair(a,b)
#define ll        long long
#define mp(a,b)   make_pair(a,b)
#define si(n)     scanf("%d",&n)
#define sl(n)     scanf("%lld",&n)
#define pi(n)     printf("%d\n",n)
#define pl(n)     printf("%lld\n",n)
#define           newline cout << endl;
#define           ff first
#define           ss second
#define           pii pair<int, int>
#define           pll pair<ll, ll>
using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.ff<<", "<<p.ss<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
    int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const int globalsize = 1e5+10;
const ll M = 1e9+7;
ll precalfactorial[globalsize];
ll precalpowers[globalsize];


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

void solve(){
    precalfactorial[0]=1;
    for(int i=1;i<globalsize;i++){
        precalfactorial[i] = (precalfactorial[i-1]*i)%M;
    }
    precalpowers[0]=1;
    for(int i=1;i<globalsize;i++){
        precalpowers[i] = (precalpowers[i-1]*2)%M;
    }
}

ll totalWays(ll n){
    if(n<=0) return 1LL;
    ll k1 = precalfactorial[n];
    ll power_to_cal = n/2+1;
    ll power_cal = precalpowers[power_to_cal];
    ll ans = ((k1)*(inverseMod(power_cal,M)))%M;
    return ans;
}

ll NCR(ll n, ll r) {
    if (r > n - r)
        r = n - r;
    ll ans = 1;
    ll i;
    for (i = 1; i <= r; i++) {
        ans = ((ans % M) * ((n - r + i + M) % M)) % M;
        ans = ((ans % M) * ((inverseMod(i, M)) % M)) % M;
    }
    return ans;
}

int main(){
    //clock_t tStart = clock();
    int test;
    // test=1;
    si(test);
    solve();
    while(test--){
        int n;
        si(n);
        int size = 1e6+10;
        int cnt[size];
        for(int i=0;i<size;i++){
            cnt[i]=0;
        }
        int tempsize = 0;
        for(int i=0;i<n;i++){
            int x;
            si(x);
            cnt[x]++;
            if(cnt[x]==1) tempsize++;
        }
        vector<pair<ll,ll> > v;
        int prefixsum[tempsize];
        int index=-1;
        for(int i=0;i<size;i++){
            if(cnt[i]){
                v.push_back(mp(i,cnt[i]));
                if(index==-1){
                    prefixsum[index+1]=cnt[i];
                    index=1;
                }
                else{
                    prefixsum[index]=prefixsum[index-1]+cnt[i];
                    index++;
                }
            }
        }
        cout << v << endl;
        for(int i=0;i<tempsize;i++){
            cout << prefixsum[i] << ' ';
        }
        newline
        
        //crux
        ll ans1 = totalWays(n);
        ll ans2 = 0 ;
        ll ans3 = 0 ;
        for(int i=v.size()-1;i>=2;i--){
            ll temp1 = v[i].ss;
            ll temp2 = prefixsum[i-2];
            
            ans3 += (temp1*temp2)%M;
            ans3 %= M;
            
//
            trace("temp1,prefixsum[i-2]",temp1,prefixsum[i-2]);
//            ll val1 = ((temp1%M) * (prefixsum[i-2]%M))%M;
//            ll val2 = (((temp1-1+M)%M) * ((prefixsum[i-2]-1+M)%M))%M;
//            ll val3 = totalWays(n-4);
//            trace("val1,val2,val3",val1,val2,val3);
//            // ans2 = ((ans2%M) + (((((val1%M)*(val2%M))%M)*(val3%M))%M))%M;
//            ans2 = ((ans2%M) + (((((val1%M)+(val2%M))%M)*(val3%M))%M))%M;
        }
        ans2 = totalWays(n-4);
        ans3*= ans2;
        ans3%=M;
        
        trace("ans1,ans3",ans1,ans3);
        ll ans = (ans1-ans3+M)%M;
        pl(ans);
        
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
