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




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k =  sI();
//    vector<long long>vec(k);
//    long long avg = 0;
//    REP(i,k){
//        vec[i]=sI();
//        avg +=vec[i];
//    }
//    avg/=k;
//    sort(vec.begin(),vec.end());
    cout<<k<<"\n";
    REP(i,k){
        cout<<i+1<<" ";
    }
    cout<<"\n"<<k<<"\n";
    REP(i,k){
        cout<<-i-1<<" ";
    }
    
    
    
    return 0;
}


//
//vector<int>vec(n);
//REP(i,n){
//    vec[i]=sI();
//}
//int m = sI();
//vector<int>v(m);
//REP(i,m){
//    v[i]=sI();
//}
//
//
//set<int>s;
//for(auto x:v){
//    for(auto y:vec){
//        if(x-y>0&& x-y<=100){
//            s.insert(x-y);
//        }
//    }
//}
//for(auto final_result:s){
//    for(auto y:vec){
//        for(auto x:){
//            if(final_result-x)
//                }
//    }
//}
//for(auto x:s){
//    cout<<x<<" ";
//    }

