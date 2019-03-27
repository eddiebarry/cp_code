
#include <climits>
#include <iostream>
#include <string>
#include <vector>
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

long ans(vector<int> &vec, int h){
    long ans = 0;
    for(auto x: vec){
        double temp = double(x) / double(h);
        ans+=ceil(temp);
    }
    return ans;
}


int main(){
    int t = sI();
    REP(i,t){
        int n = sI(), h = sI();
        vector<int> vec(n);
        REP(i,n){
            vec[i]=sI();
        }
        int upper = 1000000000, lower = 1;
        int middle;
        while (upper!=lower && upper-lower!=1) {
            middle = upper + lower;
            middle/=2;
            if(ans(vec,middle)<=h){
                upper = middle;
            }
            else if(ans(vec,middle)>h){
                lower = middle;
            }
        }
        if(upper==lower){
            cout<<upper<<"this is the first case\n";
        }
        else{
            long ans1 = ans(vec,lower);
            long ans2 = ans(vec,upper);
            if(ans1<=h){
                cout<<lower<<"\n";
            }
            else if(ans2<=h){
                cout<<upper<<"\n";
            }
        }
    }
}
