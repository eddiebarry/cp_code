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
    int p = sI(), s = sI();
    set< pair<int,int> >final_list;
    int scor[s];
    int num[s];
    REP(i,p){
        REP(i,s){
            scor[i]=sI();
        }
        REP(i,s){
            num[i]=sI();
        }
        
        set< pair<int,int> >se;
        
        REP(i,s){
            se.insert(make_pair(scor[i],num[i]));
        }
        int t = 0;
        for(auto x:se){
            scor[t]=x.first;
            num[t]=x.second;
            t++;
        }
        long long ans = 0;
        REP(i,s-1){
            int x = num[i];
            if(x>num[i+1]){
                ans++;
            }
        }
        final_list.insert(make_pair(ans,i+1));
    }
    for(auto x:final_list){
        cout<<x.second<<"\n";
    }
}
