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
    int n = sI(), r = sI();
    
    vector<int> arr(n,0);
    vector<int> heat(n,0);
    
    
    REP(i,n){
        arr[i]=sI();
    }
    
    REP(i,n){
        if(arr[i]==1){
            int left = i - r + 1, right = i + r ;
            
            
            left = max(0,left);
            right = min(n, right);
            cout<<left<<" "<<right<<"\n";
            
            heat[left] += 1;
            if(right<n){
                heat[right] -= 1;
            }
            REP(i,n){
                cout<<heat[i]<<" ";
                
            }
            cout<<"\n";


        }
    }
    
    ll sum = 0;
    REP(i,n){
        if(sum+= heat[i]){
            heat[i]= sum;
        }
    }
    REP(i,n){
        cout<<heat[i]<<" ";
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}


