#include <bits/stdc++.h>
#define MOD 1000000007LL
#define ll long long
#define ull unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define ll long long
#define intpair pair<int,int>
#define MP(i,j) make_pair(i,j)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    register int c = getchar();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar();
    }
    int n = 0;
    for( ; (c<48 || c>57); c = getchar() );
    for( ; (c>47 && c<58); c = getchar() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    if(flag){
        return n;
    }
    else{
        return n*-1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = sI();
    
    set<int> all_poss;
    //    all_poss.insert(0);
    int max = -1;
    int ans = -1;
    REP(i,n){
        int x = sI();
        if(all_poss.find(x)!=all_poss.end()){
            continue;
        }
        else if(x== max+1){
            all_poss.insert(x);
            max = x;
        }
        else{
            //cout<<i+1<<"\n";
            ans = i+1;
            break;
        }
        
    }
    cout<<ans;
    
    
    
    
    
    
    
    
    return 0;
}



