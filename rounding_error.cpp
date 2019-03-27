
#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<list>
#include<math.h>
#include<stdlib.h>
#include<limits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 10000000070
using namespace std;
int sI(){
    int x;
    cin>>x;
    return x;
}

int main(){
    int t = sI();
    REP(i,t){
        int n = sI(), l = sI();
        int ans = 0;
        REP(i,l){
            float t;
            int x = sI();
            t = (double)x/n;
            t*=100;
            int temp = t;
//            cout<<t<<" "<<temp;
            if(t-temp >= 0.5){
                temp++;
            }
            ans+=temp;
        }
        int left = n - l;
        if(left!=0){
            float min_d = (5/1000.0)*n;
            int min = ceil(min_d);
            ans+= left/min;
            float t;
            int x = left%min;
            t = (double)x/n;
            t*=100;
            int temp = t;
//            cout<<t<<" "<<temp;
            if(t-temp >= 0.5){
                temp++;
            }
            ans+=temp;
        }

        cout<<ans<<"\n";
    }
}
