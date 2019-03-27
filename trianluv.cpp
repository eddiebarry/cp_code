#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define ll long long
#define MOD 1000000007
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
using namespace std;
long long sI(){
    ll c;
    cin>>c;
    return c;
}

ll mod(ll a){return a<0?-a:a;}

ll gcd(ll a, ll b){return b==0?a:(gcd(b,a%b));}

ll num_tri(ll a){
    a%=MOD;
    ll ans = 1;
    REP(i,3){
        ans*= (a-i);
        ans%=MOD;
    }
    ans*=166666668;
    ans%=MOD;
    return ans;
}


int main(){
    ll t = sI();
    REP(i,t){
        ll x_1 = sI(), y_1 = sI();
        ll x_2 = sI(), y_2 = sI();
        ll x_3 = sI(), y_3 = sI();
        
        ll points_seg_1_2 = gcd(mod(y_2-y_1),mod(x_2-x_1))+1;
        ll points_seg_1_3 = gcd(mod(y_3-y_1),mod(x_3-x_1))+1;
        ll points_seg_2_3 = gcd(mod(y_2-y_3),mod(x_2-x_3))+1;
        
        ll total = points_seg_1_2+points_seg_2_3+points_seg_1_3 - 3;
        
        
        ll temp = num_tri(total);
        temp -= num_tri(points_seg_1_2);
        temp -= num_tri(points_seg_2_3);
        temp -= num_tri(points_seg_1_3);
        while (temp<0) {
            temp+=MOD;
        }
        cout<<temp%MOD<<"\n";
        
    }
//    cout<<gcd(0,1)<<" is th \ ";
}
