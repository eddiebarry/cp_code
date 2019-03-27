#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
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
    int n = sI(), q = sI();
    int arr[n];
    REP(i,n){
        arr[i]=sI();
    }
    REP(i,q){
        int dec = sI();
        if(dec ==1){
            int l = sI(), r = sI();
            l--;
            int max = -1;
            FOR(i,l,r,1){
                if(arr[i]>max){
                    max = arr[i];
                }
                
            }
            cout<<max<<"\n";
        }
        else{
            dec = sI();
            if(dec==1){
                int x = sI();
                x--;
                int temp = arr[x];
                FOR(i,x,n-1,1){
                    arr[i]=arr[i+1];
                }
                arr[n]=temp;
            }
            else{
                int x = sI();
                x--;
                int temp = arr[x];
                FOR(i,1,x+1,1){
                    arr[i]=arr[i-1];
                }
                arr[0]=temp;
            }
        }
    }
}
