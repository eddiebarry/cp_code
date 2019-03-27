#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    register int c = getchar_unlocked();
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
long long sLL(){
    register int c = getchar_unlocked();
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

int count_fact(long long s){
    long long ans = 0;
    for(int i = 1; i*i <=s; i++){
        if(s%i==0){
            ans+=2;
        }
        if(i*i==s){
            ans--;
        }
    }
    return ans;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = sI();
    vector<int>vec(n);
    set<int>primes;
    REP(i,n){
        vec[i]= sI();
        if(count_fact(vec[i])==2){
            primes.insert(vec[i]);
        }
    }
    int k =  sI();
    set<int>ans;
    
    REP(i,n){
        if(primes.find(vec[i])!=primes.end()){
            if(i!=0){
                ans.insert(i);
                if(ans.size()==k){
                    break;
                }
            }
            if(i+1 <= n-1){
                ans.insert(i+1);
                if(ans.size()==k){
                    break;
                }
            }
        }
    }
           int i = n-1;
           while(ans.size()<k){
               ans.insert(i);
               i--;
           }
    for(auto x:ans){
        cout<<x<<" ";
    }
    
    return 0;
}
