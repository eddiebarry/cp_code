#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define FOR(i, j, k, in) for (long long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;

long long sI(){
    long long c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    long long n = 0;
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    if(flag){
        return n;
    }
    else{
        return n*-1;
    }
}

int main(){
    long long t = sI();
    REP(z,t){
        long long n = sI(), k = sI();
        long long ans1 = 0, ans2 = 0;
        multiset<long long>vec1;
        multiset<long long>vec2;
        REP(i,n){
            if(i%2==0){
                long long x = sI();
                vec1.insert(x);
                ans1+=x;
            }
            else{
                long long x = sI();
                vec2.insert(x);
                ans2+=x;
            }
        }
        if(ans2>ans1 && n > 1){
            cout<<"YES\n";
        }
        else if(n==1){
            cout<<"NO\n";
        }
        else{
            //perform k swaps
            bool flag = true;
            REP(i,k){
                auto it = vec1.end();
                auto it2 = vec2.begin();
                --it;
                long long num1 = *it;
                long long num2 = *it2;
                if(num1 > num2){
                    //it can be swapped
                    vec1.erase(it);
                    vec2.erase(it2);
                    ans1 -= num1 - num2;
                    ans2 -= num2 - num1;
                    vec1.insert(num2);
                    vec2.insert(num1);
                }
                if(ans2 > ans1){
                    cout<<"YES\n";
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<"NO\n";
            }
        }
    }
}
