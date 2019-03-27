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

int arr[2048];
int main(){
    int n = sI(), k  =sI();
    set<int>vec[k];
    REP(i,n){
        vec[0].insert(sI());
    }
    set<int>done;
    done.insert(1);
    REP(i,k-1){
        int cn_chng = i+2;
        //find predecessor in done;
        int larger = *done.rbegin();
        //find predessor in done - cn chng
        int other = cn_chng - larger;
        for(auto x : vec[larger-1]){
            for(auto y : vec[other-1]){
                int temp = x|y;
                vec[cn_chng-1].insert(temp);
            }
        }
    }
    REP(i,k){
        for(auto x : vec[i]){
            arr[x]=1;
        }
    }
    int ans = 0;
    REP(i,2048){
        if(arr[i]==1){
            ans++;
        }
    }
    cout<<ans<<"\n";
    

}
//REP(i,n){
//    arr[sI()]=1;
//
//}
//REP(i,k-1){
//
//}


