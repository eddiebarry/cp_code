#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <cmath>
#include <iomanip>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;

int sI(){
    int c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    int n = 0;
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
//    long long x = 1;
//    int t = 31;
//    while(t--){
//        x*=2;
//    }
//    cout<<x<<"\n";
//    std::bitset<32> z(x);
//    std::cout << z;
    int n = sI(), q = sI();
    int arr[n][31];
    int y = sI();
    REP(j,31){
        arr[0][j]=y%2;
        y/=2;
    }
    REP(i,n-1){
        int x = sI();
        REP(j,31){
            arr[i+1][j]=x%2 + arr[i][j];
            x/=2;
        }
    }
    REP(i,q){
        int l = sI(), r = sI();
        l--;
        r--;
        int x = r - l + 1;
        long ans = 0;
        int an[31];
        if(l-1 < 0){
            REP(i,31){
                an[i]= arr[r][i];
            }
        }
        else{
            REP(i,31){
                an[i]= arr[r][i] - arr[l - 1][i];
            }
        }
        REP(i,31){
            ans<<=1;
            int current_index = 30-i;
            int num1 = an[current_index];
            int num0 = x - num1;
            if(num1>=num0){
                ans+=0;
            }
            else if(num1<num0){
                ans+=1;
            }
        }
        cout<<ans<<"\n";
    }
}
