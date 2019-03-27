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

int num_fish(vector<pair< int, int> >&fishes, int x){
    int ans = 0;
    for(auto y:fishes){
        if(y.first>x && y.second <=x){
            ans++;
        }
    }
    return ans;
    
}



int main(){
    int t = sI();
    REP(i,t){
        int n = sI();
        vector<int> arr(n);
        vector<pair< int, int> >fishes;
        REP(i,n){
            int sz = sI(), fact = sI();
            fishes.push_back(make_pair(sz,fact));
            arr[i]=fact;
        }
//        sort(arr.begin(),arr.end());
//        int begin = 0, end = n-1;
//        int mid;
//        while(end-begin!=1){
//            mid = end + begin;
//            mid/=2;
//            if()
//
//
//
//        }
        int best_ans = -1;
        for(auto x: arr){
            int y =num_fish(fishes,x);
            if(y>best_ans){
                best_ans =y;
            }
        }
        cout<<best_ans<<"\n";
    }
}
