#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#define ll long long
#define intpair pair<int,int>
#define MP(i,j) make_pair(i,j)
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = sI(),m = sI();;
    string a_;
    string b_;
    cin>>a_>>b_;
    
    vector<int> a;
    vector<int> b;
    
    
    REP(i,n){
        if(a_[i]=='1'){
            a.push_back(n -1-i);
        }
    }
    REP(i,m){
        if(b_[i]=='1'){
            b.push_back(m - 1-i);
        }
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    
    
    long long vec[n];
    
    long long temp = 1;
    
    
    REP(i,n){
        int idx = n-1-i;
        if(a_[idx]=='1'){
            vec[idx]=temp;
        }
        temp*=2;
        temp %= 998244353;
    }
    
    
    
    long long sum = 0;
    
    REP(i,n){
        int idx = n-1-i;
        if(a_[idx]=='1'){
            sum += vec[idx];
            sum %= 998244353;
        }
        vec[idx]=sum;
    }
    

    
    long long arr[n];
    REP(i,n){
        arr[i]= vec[n-1-i];
    }
//    REP(i,n){
//        cout<<arr[i]<<" ";
//    }
//    cout<<"\n";
    
    long long ans = 0;
    
    for(auto idx : b){
        
        int id = min(n-1, idx);
//        cout<<id<<"\n";
        
        ans += arr[id];
        ans %= 998244353;
        
        
        
    }
    cout<<ans<<"\n";
    
    
    
    
    
    
    
    
    return 0;
}



