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
    int n = sI(), k = sI();
    int arr[26];
    REP(i,k){
        arr[i]=0;
    }
    string a;
    cin>>a;
    for(auto x: a){
        arr[x-'A']++;
    }
    int min = n;
    REP(i,k){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    cout<<min*k;
    
    
    
    return 0;
}

