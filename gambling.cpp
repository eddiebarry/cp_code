#include <iostream>
#include <string>
#include <set>
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
    
    int n = sI();
    multiset<int> a;
    multiset<int> b;
    REP(i,n){
        int x = sI();
        a.insert(-x);
    }
    REP(i,n){
        int x = sI();
        b.insert(-x);
    }
    long long ans_a = 0, ans_b = 0;
    REP(i,2*n){
        if(i%2==0){
            auto it = a.begin();
            auto it_2 = b.begin();
            if(it== a.end()){
                b.erase(it_2);
                continue;
            }
            else if(it_2==b.end()){
                int x = *it;
                x*=-1;
                ans_a+=x;
                a.erase(it);
                continue;
            }
            else{
                int x = *it;
                int y = *it_2;
                x*=-1;
                y*=-1;
                
                if(x>y){
                    ans_a+=x;
                    a.erase(it);
                }
                else{
                    b.erase(it_2);
                }
            }
        }
        else{
            auto it = b.begin();
            auto it_2 = a.begin();
            if(it== b.end()){
                a.erase(it_2);
                continue;
            }
            else if(it_2==a.end()){
                int x = *it;
                x*=-1;
                ans_b+=x;
                b.erase(it);
                continue;
            }
            else{
                int x = *it;
                int y = *it_2;
                x*=-1;
                y*=-1;
                
                if(x>y){
                    ans_b+=x;
                    b.erase(it);
                }
                else{
                    a.erase(it_2);
                }
            }
        }
    }
    cout<<ans_a-ans_b;
    
    return 0;
}


