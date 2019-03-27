#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define ll long long
#define intpair pair<int,int>
#define MP(i,j) make_pair(i,j)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
ll sI(){
    ll x;
    cin>>x;
    return x;
}

ll max(ll a, ll b){
    return a<b ?b:a;
}

ll min(ll a, ll b){
    return a>b ?b:a;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n = sI(), m = sI();
    
    long long mx_nodes;
    
    
    REP(i,n+1){
        
        ll a = i;
        ll nodes = a * (a-1);
        nodes/=2;
        
        if(nodes >=m ){
            mx_nodes = i;
            break;
        }
    }
    
    
    
    
    
    long long MX = max(n - mx_nodes , 0);
    
    
    
    

    
    long long MN = max(n - m * 2, 0);
    
    cout<<MN<<" "<<MX<<"\n";

    
    
    
    
    
    
    
    
    
    
    return 0;
}




