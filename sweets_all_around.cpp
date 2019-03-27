#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
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
    int n= sI();
    vector<pair<int,int> > vec;
    REP(i,n){
        vec.push_back(make_pair(sI(),0));
        vec.push_back(make_pair(sI(),1));
    }
    sort(vec.begin(),vec.end());
    int ans = -1;
    int max = 0;
    int num_student = 0;
    REP(i,2*n){
        pair<int,int> temp = vec[i];
        if(temp.second==0){
            num_student++;
        }
        else{
            num_student--;
        }
        if(num_student>max){
            ans = temp.first;
            max = num_student;
        }
    }
    cout<<ans<<" "<<max<<"\n";
}
