#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
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

int main(){
    int t = sI();
    REP(z,t){
        int n = sI();
        int arr[n];
        REP(i,n){
            arr[i]=sI();
        }
        int max_ans = 0;
        REP(i,n){
            int ans = 1;
            long long totalwt = arr[i];
            FOR(j,i+1,n,1){
                if(totalwt <= 6*arr[j]){
                    totalwt+=arr[j];
                    ans++;
                }
            }
            if(ans > max_ans){
                max_ans=ans;
            }
        }
        cout<<"case #"<<z+1<<": "<<max_ans<<"\n";
    }
}
