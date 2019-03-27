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
    register int c;
    cin>>c;
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = sI(), k = sI();
    string s;
    cin>>s;
    
    vector<int>arr(k,0);
    for(auto x:s){
        arr[x-'A']++;
    }
    int min = n;
    for(auto x:arr){
        if(x<min){
            min = x;
        }
    }
    cout<<min*k;
    
    return 0;
}

