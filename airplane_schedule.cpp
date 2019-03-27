#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
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
    vector<int> vec(n);
    
    
    ll max = -1;
    REP(i,n){
        vec[i]=sI();
        if(vec[i]>max){
            max = vec[i];
        }
    }
    
    vector<ll> a;
    vector<ll> b;
    
    ll min_a = max;
    ll min_b = max;
    REP(i,n){
        if(vec[i] <= min_a && vec[i] <= min_b){
            //find which increaes max the least and add
            ll A = vec[i]-min_a;
            ll B = vec[i]-min_b;
            A*=-1;
            B*=-1;
            if(A<B){
                a.push_back(vec[i]);
                min_a = vec[i];
            }
            else{
                b.push_back(vec[i]);
                min_b = vec[i];
            }
            
        }
        else if(vec[i]<= min_a ){
            //add to a
            a.push_back(vec[i]);
            min_a = vec[i];
        }
        else if(vec[i] <= min_b){
            //add to b
            b.push_back(vec[i]);
            min_b = vec[i];
        }
        else{
            //find which makes it least and add
            ll A = vec[i]-min_a;
            ll B = vec[i]-min_b;
            
            
            if(A<B){
                a.push_back(vec[i]);
            }
            else{
                b.push_back(vec[i]);
            }
            
        }
        
    }
    int ans = 0;
    REP(i,a.size()){
        FOR(j,i+1, a.size(),1){
            if(a[j]<a[i]){
                ans++;
                break;
            }
        }
    }
    REP(i,b.size()){
        FOR(j,i+1, b.size(),1){
            if(b[j]<b[i]){
                ans++;
                break;
            }
        }
    }
    cout<<n - ans;
    
    
    
    
    
    
    
    
    return 0;
}
