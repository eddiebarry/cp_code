#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define NUM 32
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

long long mod(long long a){return a<0?-a:a;}

long long func(vector<int>&v){
    long long ans= 0;
    for(auto x:v){
        ans*=2;
        ans+=x;
    }
    return ans;
}


int main(){
    int t = sI();
    vector<int> v(NUM);
    set<long long>s;
    set<long long>s_r;
    FOR(i,0,NUM,1){
        v[i]=1;
        FOR(j,i+1,NUM,1){
            v[j]=1;
            long long num = func(v);
//            cout<<num<<" is num\n";
            s.insert(num);
            s_r.insert(-num);
            v[j]=0;
        }
        v[i]=0;
    }
    
    
    
    REP(i,t){
        long long n = sI();
        //find successor
        auto it = s.lower_bound(n);
        auto it_r = s_r.lower_bound(-1*n);
        
        vector<long long>v;
        if(it!=s.end()){
            v.push_back(*it);
        }
        if(it_r!=s_r.end()){
            v.push_back( (*it_r) * -1);
        }
        
        long long min_dif = INT_MAX;
        for(auto x:v){
            if(mod(n-x)<min_dif){
                min_dif = mod(n-x);
            }
        }
        cout<<min_dif<<"\n";
    }
}
