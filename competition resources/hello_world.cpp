#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<algorithm>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
using namespace std;
int sI(){
    int c;
    cin>>c;
    return c;
}


int main()
{
    int n = sI(), m = sI();
    REP(i,n){
        string s;
        cin>>s;
        cout<<"HELLO "<<s<<endl;
    }
    
    return 0;
}
