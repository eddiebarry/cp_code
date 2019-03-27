#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define LL long long
#define INTPAIR pair<int,int>
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
    
    vector<INTPAIR>vec;
    REP(i,n){
        int x = sI(), y = sI();
        vec.push_back(MP(y,x));
    }
    
    
    int max = -1;
    
    
    REP(i,n){
        INTPAIR temp = vec[i];
        
        REP(j,n){
            if(i==j){
                continue;
            }
            else{
                INTPAIR temp1 = vec[j];
                
                int mqx_tim= -1;
                
                if(temp.first <= temp1.first && temp.second <= temp1.second){
                    mqx_tim = temp1.first;
                }
                
            }
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}


