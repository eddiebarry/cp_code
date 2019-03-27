#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <iomanip>
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
//int n = sI();
//REP(i,n-1){
//    cout<<i+1<<" "<<i+2<<"\n";
//}

int main(){
    int n = sI(), m = sI(), d = sI();
    set<int> set;
    int arr[m];
    REP(i,m){
        arr[i]=sI();
        set.insert(arr[i]);
    }
    auto it = set.begin();
    unordered_set<int>min_set;
    REP(i,n){
        min_set.insert(*it++);
    }
    REP(i,m){
        if(min_set.find(arr[i])!=min_set.end()){
            cout<<arr[i]<<" ";
        }
    }
    
}
