#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#define ll long long
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    register int c = getchar();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar();
    }
    int n = 0;
    for( ; (c<48 || c>57); c = getchar() );
    for( ; (c>47 && c<58); c = getchar() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    if(flag){
        return n;
    }
    else{
        return n*-1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = sI();
    
    ll arr[n];
    
    long long sum = 0;
    

    REP(i,n){
        arr[i]=sI();
        sum += arr[i];
    }
    if(sum%3!=0){
        cout<<0;
        return 0;
    }
    REP(i,n-1){
        arr[i+1]+=arr[i];
    }
    long long x = sum/3;
    long long y = x*2;
    
    long long ans = 0;
    vector<int> x_idx;
    vector<int> y_idx;
    REP(i,n-1){
        if(arr[i]==x){
            x_idx.push_back(i);
        }
        if(arr[i]==y){
            y_idx.push_back(i);
        }
    }
    REP(i,x_idx.size() ){
        
        int idx = x_idx[i];
        auto itr = upper_bound (y_idx.begin(), y_idx.end(), idx);
        long long num = itr - y_idx.begin();
        
        num = y_idx.size() - num;
        
//        cout<<num<<"\n";
        ans+=num;
        
    }
    cout<<ans<<"\n";
    
    
    
    
    return 0;
}

