#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
    int t = sI();
    REP(i,t){
        int n = sI();
        bool front = false, back = false;
        int arr[n], fing[n];
        REP(i,n){
            fing[i]=sI();
        }
        REP(i,n){
            arr[i]=sI();
        }
        REP(i,n){
            if(fing[i]<=arr[i]){
                front = true;
            }
            else{
                front = false;
                break;
            }
        }
        REP(i,n){
            if(fing[i]<=arr[n-1-i]){
                back = true;
            }
            else{
                back = false;
                break;
            }
        }
        if(front&&back){
            cout<<"both\n";
        }
        else if(front){
            cout<<"front\n";
        }
        else if(back){
            cout<<"back\n";
        }
        else{
            cout<<"none\n";
        }
    }
}
