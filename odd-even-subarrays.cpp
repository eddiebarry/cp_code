#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iomanip>
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
#define sqrt_dt long
using namespace std;

long sI(){
    long c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    long n = 0;
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
    int n = sI();
    int arr[n];
    REP(i,n){
        arr[i]=sI();
        arr[i]%=2;
    }
    int ans[n];
    ans[0] = arr[0]==0 ? -1:1;
    REP(i,n-1){
        if(arr[i+1]==1){
            ans[i+1] = ans [i]+1;
        }
        else{
            ans[i+1] = ans [i]-1;
        }
    }
    unordered_map<long,long> map;
    REP(i,n){
        if(map.find(ans[i])==map.end()){
            map[ans[i]]=1;
        }
        else{
            map[ans[i]]++;
        }
    }
    long bias = 0;
    long fin = 0;
    REP(i,n){
        long curr_search = 0;
        curr_search+=bias;
        //cout<<curr_search<<"is the curr seacrh tem\n";
        if(map.find(curr_search)!=map.end()){
            fin += map[curr_search];
            //cout<<"map curr search is "<<map[curr_search]<<"\n";
        }
        map[ans[i]]--;
        //cout<<"map ans i is "<<map[ans[i]]<<"\n";
        if(arr[i]==1){
            bias++;
        }
        else{
            bias--;
        }
    }
    cout<<fin;
}
