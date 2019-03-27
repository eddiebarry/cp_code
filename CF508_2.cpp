#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    int c;
    cin>>c;
    return c;
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = sI();
//    cout<<n<<" is n\n";
    
    if(n<3){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
        cout<<1<<" "<<n<<"\n";
        cout<<n-1<<" ";
        REP(i,n-1){
            cout<<i+1<<" ";
        }
    }
    
    
    
    return 0;
}


