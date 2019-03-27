#include <iostream>
#include <string>
#include <vector>
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

int max(int a, int b){return a > b? a:b;}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = sI();
    int arr[n];
    REP(i,n){
        arr[i] = sI();
    }
    
    int DP[n];
    
    REP(i,n){
        DP[i]=arr[i];
    }
    REP(i,n){
        int cand  = DP[i];
        REP(j,i){
            int temp;
            if(arr[j] < arr[i]){
                temp = max(DP[i], DP[i]+ DP[j]);
                if(temp > cand){
                    cand = temp;
                }
            }

        }
        DP[i]= cand;
        
        
//        REP(i,n){
//            cout<<DP[i]<<" ";
//        }
//        cout<<"\n";
    }
    int max = -100000;
    REP(i,n){
        if(DP[i]> max){
            max =  DP[i];
        }
    }
    cout<<max;
    
    
    return 0;
}

