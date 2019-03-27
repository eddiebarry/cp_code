#include<queue>
#include<string>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
using namespace std;
int sI(){
    int c ;
    cin>>c;
    return c;
}


int main(){
    int t =  sI();
    string a,b;
    cin>>a>>b;
    long long ans= 0;
    REP(i,t){
        int A = a[i] - 'A' + 1;
        int B = b[i] - 'A' + 1;
        if(A>B){
            B = 26 + B - A;
        }
        else{
            B = B-A;
        }
//        cout<<A<<" "<<B<<"\n";
        ans += (B)/13;
        ans += (B)%13;
    }
    cout<<ans;
}
